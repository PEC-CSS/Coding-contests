#include "bits/stdc++.h"

void solve()
{
    int q;
    std::cin >> q;

    std::cout << std::max(0, (q - 30) / 7) << "\n";
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