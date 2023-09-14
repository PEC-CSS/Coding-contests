#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> adj[n];
    for (int i = 0; i < m; i++)  
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    int bad = 0;
    std::vector<int> c(n, -1);
    std::function<void(int, int)> dfs = [&](int u, int col)
    {
        c[u] = col;
        for (int v : adj[u])
        {
            if (c[v] == -1)
                dfs(v, 1 - col);
            else if (c[v] == col)
                bad = 1;
        }
    };

    for (int i = 0; i < n; i++)
    {
        if (c[i] == -1)
            dfs(i, 0);
    }

    std::cout << (bad ? "NO\n" : "YES\n");
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