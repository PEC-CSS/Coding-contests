#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll rem = (a + b + c) % 2;
    if (rem)
    {
        cout << "ODD\n";
        return;
    }
    cout << "EVEN\n";
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