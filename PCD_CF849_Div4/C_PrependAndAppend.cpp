#include "bits/stdc++.h"

using i64 = long long;

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    int ans = n;

    int i = 0, j = n - 1;
    while (i < j)
    {
        if (s[i] != s[j])
            ans -= 2, i++, j--;
        else
            break;
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}