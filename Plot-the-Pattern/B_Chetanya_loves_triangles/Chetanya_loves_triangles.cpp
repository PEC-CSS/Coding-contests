#include <bits/stdc++.h>
using namespace std;

int main()
{
    int rows;
    cin >> rows;

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 2 * rows - i; j > i; j--)
        {
            cout << " ";
        }

        for (int j = i; j >= 1; j--)
        {
            if (j == i || j == 1)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }

        cout << endl;
    }

    for (int i = rows - 1; i >= 1; i--)
    {
        for (int j = 2 * rows - i; j > i; j--)
        {
            cout << " ";
        }

        for (int j = i; j >= 1; j--)
        {
            if (j == i || j == 1)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }

        cout << endl;
    }

    return 0;
}