#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> ans;

    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < i; j++)
        {
            temp.push_back(cnt);
            cnt++;
        }
        ans.push_back(temp);
    };
    for (auto it : ans)
    {
        for (auto ele : it)
            cout << ele << " ";
        cout << "\n";
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = ans[i].size() - 1; j >= 0; j--)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}