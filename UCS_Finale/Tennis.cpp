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
    
    i64 n;
    std::cin >> n;

    std::vector<i64> fib {1, 2};
    while (fib.back() <= n)
    {
        int sz = std::size(fib);
        fib.emplace_back(fib[sz - 1] + fib[sz - 2]);
    }

    int id = std::upper_bound(std::begin(fib), std::end(fib), n) - std::begin(fib) - 1;
    std::cout << id;
    
    return 0;
}