#include "bits/stdc++.h"

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    auto factor = [&](int x)
    {
        std::vector<int> f;
        for (int i = 1; 1LL * i * i <= x; i++)
        {
            if (x % i == 0)
            {
                f.emplace_back(i);
                if (i * i != x)
                    f.emplace_back(x / i);
            }
        }

        return f;
    };

    int cnt = 0;
    int g = 1;
    std::vector<int> ans(n);

    std::function<void(int, int)> dfs = [&](int u, int p)
    {
        cnt += a[u] % g != 0;

        if (cnt <= 1)
            ans[u] = std::max(ans[u], g);

        for (int v : adj[u])
        {
            if (v != p)
                dfs(v, u);
        }

        cnt -= a[u] % g != 0;
    };

    for (const auto f : factor(a[0]))
    {
        cnt = 0;
        g = f;
        dfs(0, 0);
    }

    a[0] = 0;
    g = 0;
    dfs = [&](int u, int p)
    {
        int old = g;
        g = std::gcd(g, a[u]);
        ans[u] = std::max(ans[u], g);

        for (int v : adj[u])
        {
            if (v != p)
                dfs(v, u);
        }

        g = old;
    }; dfs(0, 0);

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];

    return 0;
}