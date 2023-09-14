#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<std::string> legal;

void solve()
{
    int n;
    std::cin >> n;

    for (auto s : legal)
    {
        if (std::stoi(s) > n)
            break;
        std::cout << s << " ";
    }

    std::cout << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    constexpr int N = 1e3 + 1;
    for (int i = 0; i < N; i++)
    {
        auto s = std::to_string(i);
        int ok = 1;
        for (int i = 1; i < std::size(s); i++)
            ok &= std::abs(s[i] - s[i - 1]) == 1;

        if (ok)
            legal.emplace_back(s);
    }
    
    while (t--)
        solve();
    
    return 0;
}