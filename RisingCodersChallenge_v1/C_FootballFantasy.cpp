#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> alice(m), bob(m);
    for (int i = 0; i < m; i++)
    {
        cin >> alice[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> bob[i];
    }
    ll aliceSum = accumulate(alice.begin(), alice.end(), 0LL);
    ll bobSum = accumulate(bob.begin(), bob.end(), 0LL);
    if (aliceSum + n - m > bobSum)
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}