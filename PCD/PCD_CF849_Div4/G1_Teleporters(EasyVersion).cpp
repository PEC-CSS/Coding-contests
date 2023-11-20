#include "bits/stdc++.h"

using i64 = long long;

void solve()
{
    int n, c;
    std::cin >> n >> c;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        b[i] = a[i] + i + 1;
    }

    std::sort(std::begin(b), std::end(b));
    int ans = 0;

    for (auto &x : b)
    {
        if (x > c)
            break;

        ans++;
        c -= x;
    }

    std::cout << ans << "\n";
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