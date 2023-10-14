#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> alice(m), bob(m);
    for (int i = 0; i < m; i++)
        cin >> alice[i];
    for (int i = 0; i < m; i++)
        cin >> bob[i];

    int score = 0;
    for (int i = 0; i < m; i++)
        score += alice[i] - bob[i];

    if (score + n - m > 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}   
    
int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
        solve();
}