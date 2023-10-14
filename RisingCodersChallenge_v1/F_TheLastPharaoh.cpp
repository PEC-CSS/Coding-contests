#include "bits/stdc++.h"

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l = 0, r = 0;
    long long ans = 0;
    while (r < n)
    {
        // find number of subarrays ending at r
        if (a[r] >= r - l + 1)
        {
            ans += r - l + 1;
            r++;
        }
        else
            l = r - (a[r] - 1);
    }

    cout << ans << "\n";
}

int main()
{
    int t;
    cin >> t;

    while (t--) 
        solve();
    
    return 0;
}