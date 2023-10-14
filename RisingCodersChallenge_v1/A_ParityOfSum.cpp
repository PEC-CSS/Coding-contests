#include <bits/stdc++.h>
using namespace std;

int* a;

int main()
{
    int n;
    cin >> n;

    a = new int[n];

    for (int i = 0; i < 10; i++)
        a[i] = i + 1;
    for (int i = 0; i < 10; i++)
        cout << a[i] << " \n";
}