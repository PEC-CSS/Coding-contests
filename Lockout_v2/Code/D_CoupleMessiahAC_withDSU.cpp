#include <bits/stdc++.h>

using i64 = long long;

class DSU
{
    std::vector<int> rnk, par;
public:
    DSU() {}
    DSU(int n) : rnk(n, 1), par(n) { std::iota(par.begin(), par.end(), 0); }
    int get(int x)
    {
        while (x != par[x]) x = par[x] = par[par[x]];
        return x;
    }
    bool unite(int x, int y)
    {
        int p1 = get(x), p2 = get(y);
        if (p1 == p2)
            return false;
        else
        {
            if (rnk[p2] > rnk[p1])
                std::swap(p1, p2);

            par[p2] = p1, rnk[p1] += rnk[p2], rnk[p2] = 0;
            return true;
        }
    }
    bool same(int x, int y)
    {
        return get(x) == get(y);
    }
    int size(int x)
    {
        return rnk[get(x)];
    }
};

int getMinimumTime(std::vector<int>& row)
{
    int n = std::size(row);
    DSU dsu(n);
    int cc = n;

    for (int i = 0; i < n; i += 2)
        cc -= dsu.unite(i, i + 1);
    for (int i = 0; i < n; i += 2)
        cc -= dsu.unite(row[i], row[i + 1]);

    return n / 2 - cc;
}

void solve()
{
    int n;
    std::cin >> n;

    n *= 2;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::cout << getMinimumTime(a) << "\n";
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