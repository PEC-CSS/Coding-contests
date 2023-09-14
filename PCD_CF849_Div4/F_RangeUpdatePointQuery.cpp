#include "bits/stdc++.h"

using i64 = long long;

void solve()
{
    int n, q;
    std::cin >> n >> q;

    std::set<int> pos;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        if (a[i] / 10 > 0)
            pos.emplace(i);
    }

    auto sum = [&](int x)
    {
        int sum = 0;
        while (x != 0)
        {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    };

    while (q--)
    {
        int t;
        std::cin >> t;

        if (t == 1)
        {
            int l, r;
            std::cin >> l >> r;
            l--, r--;

            auto start = pos.lower_bound(l);
            auto end = pos.upper_bound(r);

            std::vector<int> rem;
            for (auto it = start; it != end; it++)
            {
                a[*it] = sum(a[*it]);
                if (a[*it] / 10 == 0)
                    rem.emplace_back(*it);
            }

            for (auto del : rem)
                pos.erase(del);
        }
        else
        {
            int x;
            std::cin >> x;

            std::cout << a[x - 1] << "\n";
        }
    }
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