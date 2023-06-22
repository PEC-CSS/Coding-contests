#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

template<class Info>
struct SegmentTree
{
    int n;
    std::vector<Info> info;
    SegmentTree(int n = 0) : n(n), info(4 << std::__lg(n), Info()) {}
 
    template <typename T>
    SegmentTree(const std::vector<T> a) 
    {
        n = std::size(a);
        info.assign(4 << std::__lg(n), Info());
        std::function<void(int, int, int)> build;
        build = [&](int l, int r, int id)
        {
            if (l > r)
                return;
            if (l == r)
            {
                info[id] = Info(a[l]);
                return;
            }
 
            int m = (l + r) >> 1;
            build(l, m, id * 2 + 1);
            build(m + 1, r, id * 2 + 2);
            merge(id);
        }; 
        build(0, n - 1, 0);
    } 
    void merge(int id)
    {
        info[id] = info[id * 2 + 1] + info[id * 2 + 2];
    }
    void update(int id, int x, int nl, int nr, const Info &v)
    {
        if (nl > nr)
            return;
        if (nl == nr)
        {
            info[id] = info[id] + v;
            return;
        }
 
        int m = (nl + nr) >> 1;
        if (x <= m)
            update(2 * id + 1, x, nl, m, v);
        else
            update(2 * id + 2, x, m + 1, nr, v);
        merge(id);
    }
    void update(int x, const Info &v)
    {
        update(0, x, 0, n - 1, v);
    }
    Info get(int id, int l, int r, int nl, int nr)
    {
        if (r < nl or l > nr)
            return Info();
        if (l >= nl and r <= nr)
            return info[id];
 
        int m = (l + r) >> 1;
        return get(2 * id + 1, l, m, nl, nr) + get(2 * id + 2, m + 1, r, nl, nr);
    }
    Info get(int l, int r)
    {
        return get(0, 0, n - 1, l, r);
    };
};

struct Info 
{
    int x;
    Info(int x = inf) : x(x) {}
};

Info operator+ (Info a, Info b)
{
    if (a.x < b.x)
        return a;
    return b;
}

void solve()
{
     int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int left = 0, right = m;
    int ans = -1;

    auto good = [&](int mid)
    {
        std::vector dp(m + 1, 0);
        for (int i = 0; i < n; i++)
        {
            SegmentTree<Info> st(dp);
            std::vector ndp(m + 1, inf);
            for (int x = 0; x <= m; x++)
                ndp[x] = st.get(std::max(0, x - mid), std::min(x + mid, m)).x + (x != a[i]);

            std::swap(dp, ndp);
        }

        return *std::min_element(std::begin(dp), std::end(dp)) <= k;
    };

    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    } 

    std::cout << ans << "\n"; 
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}