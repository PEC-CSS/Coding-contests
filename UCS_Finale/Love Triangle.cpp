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

    std::map<int, int> p, s;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        s[a[i]]++;
    }

    if (n <= 2)
    {
        std::cout << "0\n";
        return;
    }

    auto get = [&](auto & m, int l, int r)
    {
        i64 ans = 0;
        for (int i = l; i <= r; i++)
            ans += m[i];

        return ans;
    };

    s[a[0]]--;
    i64 ans = 0;
    for (int i = 1; i < n - 1; i++)
    {
        p[a[i - 1]]++;
        s[a[i]]--;
        int y = a[i];

        for (int x = y - 2; x <= y + 2; x++)
        {
            for (int z = y - 2; z <= y + 2; z++)
            {
                if (std::max({x, y, z}) - std::min({x, y, z}) >= 3)
                    continue;

                ans += 1LL * p[x] * s[z];
            }
        }
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