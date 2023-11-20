#include "bits/stdc++.h"

using i64 = long long;

constexpr i64 inf = 1e18;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::tuple<int, int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, w, type;
        std::cin >> u >> v >> w >> type;

        u--, v--;
        adj[u].emplace_back(v, w, type);
        adj[v].emplace_back(u, w, type);
    }

    int start, end;
    std::cin >> start >> end;
    start--, end--;

    auto bfs = [&](int src, int type)
    {
        std::set<std::pair<i64, int>> q;
        std::vector d(n, inf);

        q.emplace(0, src);
        d[src] = 0;

        while (!q.empty())
        {
            auto [dist, u] = *std::begin(q);
            q.erase(std::begin(q));

            for (auto [v, w, col] : adj[u])
            {
                if (col != type)
                    continue;

                if (d[v] > d[u] + w)
                {
                    q.erase({d[v], v});
                    d[v] = d[u] + w;
                    q.emplace(d[v], v);
                }
            }
        }

        return d;
    };

    auto ds = bfs(start, 0);
    auto dd = bfs(end, 1);

    i64 ans = std::min(ds[end], dd[start]);
    for (int i = 0; i < n; i++)
        ans = std::min(ans, ds[i] + dd[i]);

    std::cout << (ans == inf ? -1 : ans);
    
    return 0;
}