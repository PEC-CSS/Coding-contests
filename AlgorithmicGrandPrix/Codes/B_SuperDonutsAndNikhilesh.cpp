#include "bits/stdc++.h"

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> h(n);
    std::vector a(n, std::array<int, 2>());
    for (int i = 0; i < n; i++)  
        std::cin >> h[i];

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i][1];
        a[i][0] = h[i];
    }

    std::sort(std::begin(a), std::end(a));
    std::multiset<std::pair<int, int>> m;

    std::vector<int> ans;
    int cnt = 0;
    for (int i = 0, id = 0; i < n; i++)
    {
        while (id < n and a[id][0] <= k)
        {
            m.emplace(-a[id][1], a[id][0]);
            id++;
        }

        if (m.empty())
            break;

        cnt++;
        auto [energy_gain, height] = *std::begin(m);
        m.erase(std::begin(m));

        k += -energy_gain;
        ans.emplace_back(k);
    }

    std::cout << cnt << "\n";
    for (int i = 0; i < cnt; i++)
        std::cout << ans[i] << " ";
    std::cout << "\n";
}   

int main()
{
    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}