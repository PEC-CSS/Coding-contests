#include "bits/stdc++.h"

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::set<long double> slopes;
    for (int i = 0; i < n; i++)
    {
        i64 x, y;
        std::cin >> x >> y;

        if (x == 0 and y == 0)
            continue;
        else if (x == 0)
            slopes.emplace(2e18);
        else
            slopes.emplace(1.0L * y / x);
    }

    std::cout << std::max<int>(1, std::size(slopes)) << "\n";
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