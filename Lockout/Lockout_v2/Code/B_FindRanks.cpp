#include "bits/stdc++.h"

using i64 = long long;

// This problem is just about simulating the process explained.

void solve()
{
    int n;
    std::cin >> n;  

    // (a << b) = a * (2^b)
    // Thus, 1 << b = 2^b
    const int m = 1 << n;

    std::vector a(m, std::array<int, 2>()); 
    std::vector<int> ranks(m);

    // a[i][0] = power of person-i
    // a[i][1] = i (this will help us when we remove the losers from tournament)
    for (int i = 0; i < m; i++)
    {
        std::cin >> a[i][0];
        a[i][1] = i;
    }

    // Total number of rounds where people fight = n. Why?
    for (int round = 1; round <= n; round++)
    {
        std::vector<std::array<int, 2>> winners;

        // Make players fight in order and push winner into winners list
        // i < std::size(a) instead of i < m. why?
        for (int i = 0; i < std::size(a); i += 2)
        {
            // Add winner in winner list and set rank for loser
            if (a[i][0] > a[i + 1][0])
            {
                winners.push_back(a[i]);
                ranks[a[i + 1][1]] = n + 2 - round;
            }
            else
            {
                winners.push_back(a[i + 1]);
                ranks[a[i][1]] = n + 2 - round;
            }
        }

        // Now, we have the people who won in winners list
        // Let's remove the losers for tournament and keep only winners
        a = winners;
    }

    // Last one standing will have rank-1
    ranks[a[0][1]] = 1;

    for (int i = 0; i < m; i++)
        std::cout << ranks[i] << " \n"[i == m - 1];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}