#include "bits/stdc++.h"

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    int l, r;
    std::cin >> l >> r;

    auto between = [&](int x, int l, int r)
    {
        int res = l <= x and x <= r;
        return res ? 1 : -1;
    };

    int have = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += between(a[i], l, r);
        if (sum > 0)
            have++, sum = 0;
    }

    std::cout << (have >= k and sum >= 0 ? "YES\n" : "NO\n");
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