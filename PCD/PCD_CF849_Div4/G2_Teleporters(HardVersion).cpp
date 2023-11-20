#include "bits/stdc++.h"

using i64 = long long;

void solve()
{
    int n, c;
    std::cin >> n >> c;

    std::vector<int> a(n);
    std::vector<std::array<i64, 2>> b(n);

    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        b[i] = {a[i] + std::min(i + 1, n - i), a[i] + i + 1};
    }

    std::sort(std::begin(b), std::end(b));
    std::vector<i64> pref(n);
    pref[0] = b[0][0];

    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + b[i][0];

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i][1] > c)
            continue;

        int have = c;
        int left = 0, right = n - 1;
        int cur_ans = -1;

        while (left <= right)
        {
            int mid = std::midpoint(left, right);
            if (mid >= i)
                have = c + b[i][0] - b[i][1];
            else
                have = c - b[i][1];

            if (pref[mid] <= have)
                cur_ans = mid, left = mid + 1;
            else
                right = mid - 1;
        }

        ans = std::max(ans, cur_ans + 2 - (cur_ans >= i));
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