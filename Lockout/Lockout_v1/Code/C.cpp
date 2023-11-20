#include "bits/stdc++.h"

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];

    std::map<int, int> m;
    m[0] = 0;
    for (int i = 0; i < n; i++)
        m[a[i]] = 0;

    int num = 1;
    for (auto &[_, f] : m)
        f = num++;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += m[a[i]] > m[0];
        for (int j = i - 1; j >= 0; j--)
            ans += m[a[i]] > m[a[j]];
    }

    std::cout << ans;
    
    return 0;
}