#include "bits/stdc++.h"

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    int z = 0;
    for (int i = 0; i < n - 1; i++)
        z = std::gcd(z, a[n - 1] - a[i]);

    i64 y = 0;
    for (int i = 0; i < n; i++)
        y += (a.back() - a[i]) / z;

    std::cout << y << " " << z << "\n";
}

int main()
{
    int t;
    std::cin >> t;
    
    while (t--)
        solve();

    return 0;
}