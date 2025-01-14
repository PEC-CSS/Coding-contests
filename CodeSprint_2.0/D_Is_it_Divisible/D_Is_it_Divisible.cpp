#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void solve()
{
    string n;
    ll p;
    cin >> n >> p;
    ll ans = 0;
    for (int i = 0; i < n.size(); i++)
    {
        ans = ans * 10 + (n[i] - '0');
        ans %= p;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
