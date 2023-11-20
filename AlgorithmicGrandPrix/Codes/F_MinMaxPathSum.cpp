#include "bits/stdc++.h"

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<std::pair<int, int>>> adj(2 * n);
    for (int i = 0; i < 2 * n - 1; i++)  
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    i64 min = 0, max = 0;
    std::vector<int> sz(n * 2, 1);

    auto dfs = [&](auto &&self, int u, int p) -> void
    {
        for (auto [v, w] : adj[u])
        {
            if (v == p)
                continue;
            self(self, v, u);
            sz[u] += sz[v];

            if (sz[v] % 2 == 1)
                min += w;

            max += 1LL * std::min(sz[v], 2 * n - sz[v]) * w;
        }
    }; dfs(dfs, 0, 0);

    std::cout << min << " " << max << "\n";
}

int main()
{
    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}