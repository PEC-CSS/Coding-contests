#include "bits/stdc++.h"

using i64 = long long;

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    int x = 0, y = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
            x--;
        else if (s[i] == 'R')
            x++;
        else if (s[i] == 'U')
            y++;
        else
            y--;

        if (x == 1 and y == 1)
            ans = 1;
    }

    std::cout << (ans ? "YES\n" : "NO\n");
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