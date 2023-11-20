#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void solve()
{
    set<string> s;
    s.insert("ACM");
    s.insert("AMC");
    s.insert("CAM");
    s.insert("CMA");
    s.insert("MCA");
    s.insert("MAC");
    string st;
    cin >> st;
    if (s.find(st) != s.end())
    {
        cout << "ACM\n";
        return;
    }
    cout << "NOPE\n";
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