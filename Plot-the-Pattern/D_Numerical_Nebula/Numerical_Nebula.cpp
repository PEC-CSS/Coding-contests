#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt1 = n / 2;
    int cnt2 = n / 2;
    int cnt3 = 1;
    bool check = false;
    for (int i = 0; i < n + 2; i++)
    {
        cout << '*';
    }
    cout << endl;
    for (int j = 0; j < n; j++)
    {
        cout << '*';
        for (int i = 0; i < n; i++)
        {
            if (i == cnt1 || i == cnt2)
            {
                cout << cnt3;
                cnt3++;
                if (cnt3 == 10)
                {
                    cnt3 = 0;
                }
            }
            else
            {
                cout << ' ';
            }
        }
        if (check == false)
        {
            cnt1++;
            cnt2--;
            if (cnt2 == 0)
            {
                check = true;
            }
        }
        else
        {
            cnt1--;
            cnt2++;
        }
        cout << '*' << endl;
    }
    for (int i = 0; i < n + 2; i++)
    {
        cout << '*';
    }
    cout << endl;
    return 0;
}