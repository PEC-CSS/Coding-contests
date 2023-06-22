#include "bits/stdc++.h"

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::map<int, int> freq;
    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;
        freq[x]++;
    }

    /*
     * Om can change only K elements.
     * Is it always better to increase frequency of maximum element?
     * Let maximum element frequency be a, and frequency of any other element be b.
     * LHS = (a + 1) * a * (a - 1) + (b - 1) * (b - 2) * (b - 3)
     * RHS = a * (a - 1) * (a - 2) + (b + 1) * b * (b - 1)
     * if LHS > RHS, then our claim is true. Try to prove it yourself.
     * Similarly you can prove that number with minimum frequency should be changed
    */

    std::multiset<int> m;
    for (auto &[num, f] : freq)
        m.emplace(f);
    
    while (k-- and std::size(m) > 1)
    {
        int min = *std::begin(m);
        m.erase(std::begin(m));
        int max = *(--std::end(m));
        m.erase(--std::end(m));

        min--, max++;
        m.emplace(max);
        if (min)
            m.emplace(min);
    }

    // Ignoring the division of 6. Will it affect our answer?
    i64 om = 0;
    for (auto x : m)
        om += 1LL * x * (x - 1) * (x - 2);

    i64 abhilash = 1LL * n * (n - 1) * (n - 2) - om;
    std::cout << (om >= abhilash ? "YES\n" : "NO\n");
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