#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll right = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (right < n && v[right] >= right - i + 1)
        {
            right++;
        }
        ans += right - i;
    }
    cout << ans << endl;
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