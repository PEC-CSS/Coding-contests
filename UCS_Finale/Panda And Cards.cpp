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
        
    constexpr int n = 5;
    std::array<int, 101> a{};

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        a[x]++;
        sum += x;
    }

    int rem = 0;
    for (int i = 100; i > 0; i--)
    {
        if (a[i] >= 3)
            rem = std::max(rem, 3 * i);
        else if (a[i] >= 2)
            rem = std::max(rem, 2 * i);
    }

    std::cout << sum - rem;
    
    return 0;
}