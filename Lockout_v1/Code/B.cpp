#include "bits/stdc++.h"

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 n, a, b;
    std::cin >> n >> a >> b;

    std::cout << n / (a + b) * a + std::min(a, n % (a + b));
    
    return 0;
}