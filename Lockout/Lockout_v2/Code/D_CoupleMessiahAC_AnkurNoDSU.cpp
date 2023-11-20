#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

int getMinimumTime(vector<int> &row)
{
    int n = row.size();
    vector<int> curr_partner(n);
    int ans = 0;
    for (int i = 0; i < n; i += 2)
    {
        int x = row[i];
        curr_partner[x] = row[i + 1];
        curr_partner[row[i + 1]] = x;
    }
    for (int i = 0; i < n; i++)
    {
        if (i % 2)
        {
            if (curr_partner[i] != i - 1)
            {
                ans++;
                int currPartnerOfRequiredPartner = curr_partner[i - 1];
                int currentpartnerOfUs = curr_partner[i];
                curr_partner[i] = i - 1;
                curr_partner[i - 1] = i;
                curr_partner[currPartnerOfRequiredPartner] = currentpartnerOfUs;
                curr_partner[currentpartnerOfUs] = currPartnerOfRequiredPartner;
            }
        }
        else
        {
            if (curr_partner[i] != i + 1)
            {
                ans++;
                int currPartnerOfRequiredPartner = curr_partner[i + 1];
                int currentpartnerOfUs = curr_partner[i];
                curr_partner[i] = i + 1;
                curr_partner[i + 1] = i;
                curr_partner[currPartnerOfRequiredPartner] = currentpartnerOfUs;
                curr_partner[currentpartnerOfUs] = currPartnerOfRequiredPartner;
            }
        }
    }
    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    vector<int> v(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> v[i];
    }
    cout << getMinimumTime(v) << endl;
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