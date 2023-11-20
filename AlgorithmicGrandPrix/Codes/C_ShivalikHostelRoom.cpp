#include "bits/stdc++.h"

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) 
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));

    std::vector qry(k, std::array<int, 2>());
    for (auto &[c, s] : qry)
        std::cin >> c >> s;

    std::sort(std::begin(qry), std::end(qry), [&](const auto &x, const auto &y)
    {
        return x[1] > y[1];
    });

    for (int i = 0, id = 0; i < n and id < k; id++)
    {   
        auto [c, s] = qry[id];
        while (i < n and c > 0)
        {
            a[i] = std::max(a[i], s);
            i++;
            c--;
        }
    }

    std::cout << std::accumulate(std::begin(a), std::end(a), 0LL);
}