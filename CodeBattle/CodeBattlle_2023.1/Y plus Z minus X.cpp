#include "bits/stdc++.h"

constexpr int inf = std::numeric_limits<int>::max();
    
void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::multiset<int> pref, suff;
    for (int i = 1; i < n; i++)
        suff.emplace(a[i]);

    int ans = inf;
    for (int j = 1; j < n; j++)
    {
        pref.emplace(a[j - 1]);
        suff.erase(suff.find(a[j]));

        int y = a[j];
        auto it_x = pref.lower_bound(y);
        if (it_x == std::begin(pref))
            continue;

        auto it_z = suff.upper_bound(y);
        if (it_z == std::end(suff))
            continue;

        int x = *std::prev(it_x), z = *it_z;
        ans = std::min(ans, y + z - x);
    }

    std::cout << (ans < inf ? ans : -1) << "\n";
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