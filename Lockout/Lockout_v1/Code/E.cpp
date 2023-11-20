#include "bits/stdc++.h"

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    i64 l;
    std::cin >> n >> l;

    std::multiset<i64> m;
    i64 s = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        m.emplace(x);
        s += x;
    }

    if (l != s)
        m.emplace(l - s);
    i64 ans = 0;
    while (std::size(m) > 1)
    {
        auto min1 = *std::begin(m);
        m.erase(std::begin(m));
        auto min2 = *std::begin(m);
        m.erase(std::begin(m));

        ans += min1 + min2;
        m.emplace(min1 + min2);
    }

    std::cout << ans << "\n";
    
    return 0;
}