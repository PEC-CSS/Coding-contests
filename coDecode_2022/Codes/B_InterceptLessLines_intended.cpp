#include "bits/stdc++.h"

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::pair<i64, i64>> a;
    for (int i = 0; i < n; i++) {
        i64 x, y;
        std::cin >> x >> y;

        if (x != 0 or y != 0) {
            a.emplace_back(x, y);
        }
    }

    if (n == 1 and !a.empty()) {
        std::cout << "1\n";
        return;
    }

    std::set<std::pair<i64, i64>> slopes;

    auto convertToFraction = [&](i64 x, i64 y) -> std::pair<int, int>
    {
        if (std::abs(x) == 0) {
            y = 1;
            x = 0;
        } else if (std::abs(y) == 0) {
            x = 1;
            y = 0;
        } else {
            i64 g = std::gcd(x, y);
            assert(g != 0);
            x /= g, y /= g;
        }

        if ((x ^ y) < 0) {
            x = -std::abs(x), y = std::abs(y);
        } else {
            x = std::abs(x), y = std::abs(y);
        }

        return {x, y};
    };

    for (auto [x, y] : a) {
        slopes.insert(convertToFraction(x, y));
    }

    std::cout << slopes.size() << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::freopen("handmade_7.txt", "r", stdin);
    std::freopen("handmade_7_out.txt", "w", stdout);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();

    return 0;
}