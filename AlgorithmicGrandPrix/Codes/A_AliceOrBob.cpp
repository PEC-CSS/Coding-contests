#include "bits/stdc++.h"

using i64 = long long;

void solve()
{
    int a, b;
    std::cin >> a >> b;
    
    int c = std::min(a % b, b - a % b);
    int k1 = (c - a) / b;
    int k2 = (-c - a) / b;
    
    i64 A = a + 1LL * k1 * b;
    i64 B = a + 1LL * k2 * b;
    
    if (A != B and std::abs(A) == std::abs(B))
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}

int main()
{
    int t;
    std::cin >> t;
    
    while (t--) 
        solve();
}