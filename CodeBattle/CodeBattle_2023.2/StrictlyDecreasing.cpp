#include "bits/stdc++.h"

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[j] > a[i] and a[j] - a[i] >= j - i)
                dp[i] = std::max(dp[i], dp[j] + 1);
        }
    }

    int ans = n;
    for (int i = 0; i < n; i++)
        ans = std::min(ans, n - dp[i]);

    std::cout << ans << "\n";
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