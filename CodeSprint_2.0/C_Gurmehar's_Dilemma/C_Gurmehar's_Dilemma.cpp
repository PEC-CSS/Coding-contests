#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void solve()
{
    ll n, p, k;
    cin >> n >> p >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    if (p <= 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (k == 0)
                break;
            if (v[i] <= 0)
            {
                v[i] *= p;
                k--;
            }
        }
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (k == 0)
                break;
            if (v[i] >= 0)
            {
                v[i] *= p;
                k--;
            }
        }
    }

    cout << accumulate(v.begin(), v.end(), 0LL) << endl;
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
