#include "bits/stdc++.h"

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::map<int, std::vector<int>> num;
    std::vector<std::vector<std::pair<int, int>>> a(n);

    for (int i = 0; i < n; ++i)
    {
        int m;
        std::cin >> m;

        for (int j = 0; j < m; ++j)
        {
            int p, e;
            std::cin >> p >> e;

            a[i].emplace_back(p, e);
            num[p].push_back(e);
        }
    }

    /*
     * We need only max two power of each prime p. 
     * Since LCM = product of (p_i ^ max(e_j)). 
     * So if only i-th number has max power of p_i then it is bound to give a new LCM.
     */
    for (auto &[_, p] : num)
    {
        std::sort(std::begin(p), std::end(p), std::greater<int>());
        p.resize(2);
    }

    int ans = 0, lonely = 0;
    for (int i = 0; i < n; i++)
    {
        int can = 0;
        for (auto &[p, e] : a[i])
        {
            if (e == num[p][0] and num[p][1] != num[p][0])
                can = 1;
        }

        ans += can;
        lonely |= !can;
    }

    std::cout << ans + lonely;

    return 0;
}