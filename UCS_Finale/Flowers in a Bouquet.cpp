#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    i64 s;
    std::cin >> s;

    auto good = [&](i64 mid)
    {
        i64 can = 0;
        for (int i = 0; i < n; i++)
            can += a[i] / mid;
        
        return can >= s;
    };

    i64 left = 1, right = 1e12;
    i64 ans = 0;

    while (left <= right)
    {
        i64 mid = (left + right) / 2;
        if (good(mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    std::cout << ans << '\n';
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