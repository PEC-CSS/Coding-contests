#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(int n, int d, vector<int> a)
{
    int total = 0;
    for (auto &i : a)
    {
        total += i;
    }
    d %= total;
    for (int i = 1; i < a.size(); i++)
    {
        a[i] += a[i - 1];
    }
    int index = 0;
    int dist = 1e18;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = abs(a[i] - d);
        temp = min(temp, total - temp);
        int j = (i + 1) % n;
        if (temp < dist)
        {
            index = j;
            dist = temp;
        }
        else if (temp == dist && j < index)
        {
            index = j;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int temp = abs(a[i] - d);
        temp = min(temp, total - temp);
        if (temp == dist) cnt++;
    }
    if (cnt > 1)
    {
        return;
    }
    cout << index << "\n";
    cout << dist;
}

int32_t main()
{
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    solve(n, d, a);
    return 0;
}