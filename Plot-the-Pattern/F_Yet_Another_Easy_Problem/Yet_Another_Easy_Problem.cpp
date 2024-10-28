#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int cnt = 0;
    int cnt2 = 0;
    int cnt3 = 9;
    for (int i = 0; i < 2 * n * a; i++)
    {
        int tmp1 = i % n;
        for (int j = 0; j < 2 * n * b; j++)
        {
            int tmp2 = j % n;
            if (tmp1 == 0 || tmp1 == (n - 1))
            {
                cout << '*';
            }
            else if (tmp2 == 0 || tmp2 == (n - 1))
            {
                cout << '*';
            }
            else
            {
                if (cnt == 0)
                {
                    if (tmp1 + tmp2 == n - 1)
                    {
                        if (tmp1 == tmp2 && tmp1 == (n / 2) && n % 2 == 1)
                        {
                            cout << cnt2;
                            cnt2++;
                            if (cnt2 == 10)
                            {
                                cnt2 = 0;
                            }
                        }
                        else
                        {
                            cout << '*';
                        }
                    }
                    else
                    {
                        cout << ' ';
                    }
                }
                else
                {
                    if (tmp1 == tmp2)
                    {
                        if (tmp1 == (n / 2) && n % 2 == 1)
                        {
                            cout << cnt3;
                            cnt3--;
                            if (cnt3 == -1)
                            {
                                cnt3 = 9;
                            }
                        }
                        else
                        {
                            cout << '*';
                        }
                    }
                    else
                    {
                        cout << ' ';
                    }
                }
            }
            if (tmp2 == (n - 1))
            {
                cnt++;
                cnt %= 2;
            }
        }
        if (tmp1 == (n - 1))
        {
            cnt++;
            cnt %= 2;
        }
        cout << endl;
    }
    return 0;
}