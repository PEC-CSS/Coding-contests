#include "bits/stdc++.h"

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        a[i] = (a[i] > 0 ? 1 : 0);
    }

    std::map<int, std::vector<int>> c;
    c[0] = a;

    auto add = [&](int x, int y)
    {
        int ans = (x + y) % n;
        ans = (ans + n) % n;
        assert(ans >= 0);
        return ans;
    };

    auto subtract = [&](int x, int y)
    {
        int ans = (x - y) % n;
        ans = (ans + n) % n;
        assert(ans >= 0);
        return ans;
    };

    for (int i = 1; i < 31; i++)
    {
        c[1 << i].resize(n);
        for (int j = 0; j < n; j++)
            c[1 << i][j] = c[0][subtract(j, 1 << i)] ^ c[0][add(j, 1 << i)];
    }

    auto make = [&](int from, int to)
    {
        if (c.contains(to))
            return;

        c[to].resize(n);
        for (int i = 0; i < n; i++)
            c[to][i] = c[from][subtract(i, from - to)] ^ c[from][add(i, from - to)];

        return;
    };

    int start = 0;
    for (int i = 0; i < 31; i++)
    {
        if ((m >> i) & 1)
        {
            make(start, start + (1 << i));
            start += (1 << i);
        }
    }

    std::cout << std::accumulate(std::begin(c[m]), std::end(c[m]), 0) << "\n";
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