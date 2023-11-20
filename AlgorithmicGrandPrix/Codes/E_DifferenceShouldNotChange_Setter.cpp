#include "bits/stdc++.h"

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    if (n <= 3)
    {
        std::cout << "1\n" << a[0] << "\n";

        std::cout << n - 1 << "\n";
        for (int i = 1; i < n; i++)
            std::cout << a[i] << " ";
        std::cout << "\n";
        return;
    }
    
    std::vector<int> b, c;
    std::sort(std::begin(a), std::end(a));
    auto work = [&](int id1, int id2)
    {
        b.emplace_back(a[id1]);
        b.emplace_back(a[id2]);
        int d = b[1] - b[0];
        
        for (int i = 0; i < n; i++)
        {
            if (i == id1 || i == id2)
                continue;

            if (a[i] - b.back() == d)
                b.emplace_back(a[i]);
            else
                c.emplace_back(a[i]);
        }

        if (std::size(c) <= 2)
            return true;

        d = 0;
        for (int i = 1; i < std::size(c); i++)
            d = std::gcd(d, c[i] - c[i - 1]);

        std::multiset<int> need;
        for (int i = 1; i < std::size(c); i++)
        {
            if (c[i] - c[i - 1] != d)
            {
                int x = c[i - 1];
                while (x + d != c[i])
                {
                    if (std::size(need) > std::size(b))
                        return false;

                    x += d;
                    need.emplace(x);
                }
            }
        }

        while (!need.empty())
        {
            int min = *std::begin(need);
            auto it = std::find(std::begin(b), std::end(b), min);

            if (it == std::end(b))
                return false;

            for (auto p = it; p != std::end(b); p++)
            {
                auto del = need.find(*p);
                if (del != std::end(need))
                    need.erase(del);
            }

            c.insert(std::end(c), it, std::end(b));
            b.erase(it, std::end(b));
        }
        std::sort(std::begin(c), std::end(c));
        for (int i = 2; i < std::size(c); i++)
        {
            if (c[i] - c[i - 1] != c[1] - c[0])
                return false;
        }
        
        return true;
    };

    for (int i = 0; i < 3; i++)  
    {
        int id1 = i, id2 = (i + 1) % 3;
        if (id1 > id2)
            std::swap(id1, id2);

        auto possible = work(id1, id2);
        if (possible)
        {
            std::cout << std::size(b) << "\n";
            for (int x : b)
                std::cout << x << " ";
            std::cout << "\n";

            std::cout << std::size(c) << "\n";
            for (int x : c)
                std::cout << x << " ";
            std::cout << "\n";
            return;
        }

        b.clear();
        c.clear();
    }

    std::cout << "-1\n";
}

int main()
{
    int t;
    std::cin >> t;
    
    while (t--)
        solve();

    return 0;
}