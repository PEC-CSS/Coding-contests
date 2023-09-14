#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::string s;
    std::cin >> n >> s;

    std::string ans;
    for (auto ch : s)
    {
        if (ch <= '1')
            continue;

        if (ch <= '3' or ch == '5' or ch == '7')
            ans += ch;
        else if (ch == '4')
            ans += "223";
        else if (ch == '6')
            ans += "35";
        else if (ch == '8')
            ans += "2227";
        else 
            ans += "3327";
    }

    std::sort(std::rbegin(ans), std::rend(ans));

    std::cout << ans;

    return 0;
}