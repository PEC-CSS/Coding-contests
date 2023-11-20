#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    ll mini = v[0].second;
    for (int i = 1; i < n; i++)
    {
        if (v[i].second < mini)
        {
            cout << "NEW PHONE\n";
            return;
        }
        mini = max(mini, v[i].second);
    }
    cout << "OLD IT IS\n";
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