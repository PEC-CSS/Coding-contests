#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    std::vector<std::vector<int>> phones(n);
    for (int i = 0; i < n; i++)
    {
        int price, value;
        cin >> price >> value;
        phones[i] = {price, value};
    }

    sort(phones.begin(), phones.end());
    for (int i = 0; i < n - 1; i++)
    {
        // (i, i + 1) compare ho raha hai
        // i = n - 1 hua toh i + 1 = n ho jaayega 
        // index out of bound
        if (phones[i][0] < phones[i + 1][0]
            and phones[i][1] > phones[i + 1][1])
        {
            cout << "NEW PHONE";
            return 0;
        }
    }

    cout << "OLD IT IS";
}