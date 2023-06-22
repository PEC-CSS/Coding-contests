#include "bits/stdc++.h"

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int a, b, k;
    std::cin >> a >> b >> k;

    // Find all common divisor of a and b
    std::vector<int> commonDivisor;
    for (int i = 1; i <= std::min(a, b); i++)
    {
        // if i divides both a and b then it is a common divisor of a, b
        if (a % i == 0 and b % i == 0)
            commonDivisor.push_back(i);
    }

    // sort in descending order
    std::sort(commonDivisor.begin(), commonDivisor.end(), std::greater<int>());
    
    // print the k-th element i.e. element at index k - 1.
    std::cout << commonDivisor[k - 1];
    
    return 0;
}