#include <bits/stdc++.h>
using namespace std;
string generate(int cnt, int n)
{
    string ans;
    if (2 * cnt >= n)
    {
        for (int i = 0; i < n; i++)
        {
            ans += '*';
            ans += ' ';
        }
        return ans;
    }
    else
    {
        for (int i = 0; i < cnt; i++)
        {
            ans += '*';
            ans += ' ';
        }
        for (int i = 0; i < n - 2 * cnt; i++)
        {
            ans += ' ';
            ans += ' ';
        }
        for (int i = 0; i < cnt; i++)
        {
            ans += '*';
            ans += ' ';
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<string> v1;
    int startvalue = (n / 2) + 1;
    for (int i = startvalue; i >= 1; i--)
    {
        cout << generate(i, n) << "\n";
    }
    for (int i = 2; i <= startvalue; i++)
    {
        cout << generate(i, n) << "\n";
    }
}