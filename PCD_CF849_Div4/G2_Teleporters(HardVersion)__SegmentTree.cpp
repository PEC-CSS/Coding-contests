#include "bits/stdc++.h"

using i64 = long long;

template<typename T, class F = std::function<T(const T&, const T&)>>
struct SegmentTree
{
    const int n;
    const T null_val;
    std::vector<T> tree;
    F f;

    template <typename G>
    SegmentTree(const std::vector<G> in, const T null_val, const F& f) 
        : n(int(std::size(in))), tree(2 * n, null_val), f(f), null_val(null_val)
    {
        for (int i = 0; i < n; ++i)
            tree[i + n] = in[i];

        for (int i = n - 1; i >= 0; i--)
            tree[i] = f(tree[i << 1], tree[i << 1 | 1]);
    }
    void add(int id, T x)
    {
        T val = x - get(id, id);
        update(id, val);
    }
    void update(int id, T val)
    {
        for (tree[id += n] = val; id >>= 1; )
            tree[id] = f(tree[id << 1], tree[(id << 1) | 1]);
    }
    T get(int l, int r) 
    {
        T resL = null_val, resR = null_val;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                resL = f(resL, tree[l++]);
            if (r & 1)
                resR = f(tree[--r], resR);
        }

        return f(resL, resR);
    }
};

void solve()
{
    int n, c;
    std::cin >> n >> c;

    std::vector<int> a(n), cost(n);
    std::vector<std::array<i64, 2>> b(n);

    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        b[i] = {a[i] + std::min(i + 1, n - i), a[i] + i + 1};
        cost[i] = a[i] + std::min(i + 1, n - i);
    }

    std::sort(std::begin(b), std::end(b));
    std::sort(std::begin(cost), std::end(cost));
    SegmentTree<i64> st(cost, 0, [&](auto x, auto y){ return x + y; });

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i][1] > c)
            continue;

        int have = c - b[i][1];
        int left = 0, right = n - 1;
        int cur_ans = -1;

        int old = cost[i];
        st.update(i, 0);

        while (left <= right)
        {
            int mid = std::midpoint(left, right);

            if (st.get(0, mid) <= have)
                cur_ans = mid, left = mid + 1;
            else
                right = mid - 1;
        }

        ans = std::max(ans, cur_ans + 2 - (cur_ans >= i));
        st.update(i, old);
    }

    std::cout << ans << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}