#include "bits/stdc++.h"

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        if (i > 0 and a[i] != a[i - 1])
            m[a[i] - a[i - 1]]++;
    }

    int q;
    std::cin >> q;

    std::vector<std::pair<i64, int>> weight;
    for (auto [num, f] : m)
    {
        for (int i = 1, j = 1; ; i *= 2, j++)
        {
            if (f - i > 0)
            {
                weight.emplace_back(1LL * i * num, i);
                f -= i;
            }
            else
            {
                weight.emplace_back(1LL * f * num, f);
                break;
            }
        }
    }

    constexpr int N = 3e5 + 2;
    constexpr int inf = 1e9;
    std::vector<int> dp(N, inf);
    dp[0] = 0;

    for (int i = 0; i < std::size(weight); i++)
    {
        std::vector<int> ndp(N, inf);
        ndp[0] = 0;
        for (int j = 1; j < N; j++)
        {
            ndp[j] = dp[j];
            if (j - weight[i].first >= 0)
                ndp[j] = std::min(ndp[j], dp[j - weight[i].first] + weight[i].second);
        }

        std::swap(dp, ndp);
    }

    while (q--)
    {   
        int k;
        std::cin >> k;

        std::cout << (dp[k] == inf ? -1 : dp[k]) << " \n"[q == 0];
    }
    
    return 0;
