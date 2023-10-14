#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void solve()
{
    string s, y;
    cin >> s >> y;
    ll k;
    cin >> k;
    map<char, char> mpp;
    for (int i = 0; i < k; i++)
    {
        char a, b;
        cin >> a >> b;
        mpp[a] = b;
        mpp[b] = a;
    }
    ll n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == y[i])
        {
            continue;
        }
        if (mpp[s[i]] == y[i])
        {
            continue;
        }
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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