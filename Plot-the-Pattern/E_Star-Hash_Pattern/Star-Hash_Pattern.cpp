#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> vec(2 * n, vector<char>(2 * n, '*'));
    int i = 1;
    while (i < n)
    {
        int rs = i, cs = i, re = 2 * n - i, ce = 2 * n - i;
        int rowStart = rs, colStart = cs;
        while (rs != re)
        {
            vec[rs][cs] = '#';
            vec[rs][ce - 1] = '#';
            rs++;
        }
        rs = rowStart;
        while (cs != ce)
        {
            vec[rs][cs] = '#';
            vec[re - 1][cs] = '#';
            cs++;
        }
        i += 2;
    }

    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            cout << vec[i][j];
        }
        cout << "\n";
    }
}