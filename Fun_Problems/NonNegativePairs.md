# [3. Non Negative Pairs](https://www.hackerrank.com/contests/testing-1669399991/challenges/non-negative-pairs)

Do as instructed in problem but you cannot directly multiply $A_{i, j}$ and $A_{j, i}$ because it will go out of range of long long too. **BUT** you can use python, java inbuilt big-integers or use `__int128` in c++ to do so without getting any overflow problem. But these aren't the intended solution.

### Approach-1
---

- $A_{i, j} := signum(A_{i, j})$ where signum(x) is defined as following:
- <img src = "https://wikimedia.org/api/rest_v1/media/math/render/svg/cbb2c65f0f33af6f17bb6515a8843041625a3626" style="background-color:white" />
- Now simply do as intructed in question, you will not face any overflow issue.

### Approach-2
---

- Do case work:
	- Let $A_{i, j} = x$ and $A_{j, i} = y$
	- If $(x \geq 0$ and $y \geq 0)$ or $(x \leq 0$ and $y \leq 0)$ then increase valid pair count otherwise do nothing.

### Approach-3
---

- Use bitwise xor $(\oplus)$
- If two non-zero numbers have opposite sign then their bitwise xor will be negative.
- If two non-zero number have same sign then their bitwise xor will be positive.
- The only problem is when one number is $0$ and other is some negative number say, $-x$. In this case bitwise xor becomes negative, You can handle this case separately.
- So for all bounded $(i, j)$, if $a_{i, j} = 0 or a_{j, i} = 0 or a_{i, j} \oplus a_{j, i} = 0$ then that pair is valid.

<details>

<summary> Approach-1 (Sambhav's code) </summary>

```cpp
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,valid_pairs=0,arr[100][100];
        cin>>n>>m;
        int t=min(m,n);
        long long temp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>temp;
                if(temp!=0)
                {
                    temp=temp/(abs(temp));
                }
                arr[i][j]=temp;
            }
        }
        for(int i=0;i<t;i++)
        {
            for(int j=i;j<t;j++)
            {
                //cout<<arr[i][j]<<" ";               //
                if(arr[i][j]*arr[j][i]>=0)
                {
                    valid_pairs++;
                    if(i!=j)
                    {
                        valid_pairs++;
                    }
                }
            }
            //cout<<endl;                             //
        }
        cout<<valid_pairs<<endl;
    }
}
```

</details>

<details>

<summary> Approach-2 </summary>

```cpp
#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector a(n, std::vector<i64>(m));

    for (int i = 0; i < n; i++)  
    {
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];
    }

    int last = std::min(n, m);
    int count = 0;
    for (int i = 0; i < last; i++)
    {
        for (int j = 0; j < last; j++)
        {
            bool isPositiveOrZero = (a[i][j] >= 0 and a[j][i] >= 0);
            bool isNegativeOrZero = (a[i][j]<= 0 and a[j][i] <= 0);
            count += (isPositiveOrZero or isNegativeOrZero);
        }
    }

    std::cout << count << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}
```

</details>

<details>

<summary> Approach-3 </summary>

```cpp
#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;
    
    std::vector a(n, std::vector<i64>(m));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];
    }
    
    int end = std::min(n, m);
    int valid_pairs = 0;
    for (int i = 0; i < end; i++)
    {
        for (int j = 0; j < end; j++)
            valid_pairs += (a[i][j] ^ a[j][i]) >= 0 or a[i][j] == 0 or a[j][i] == 0;
    }
    
    std::cout << valid_pairs << "\n";
}

int main()
{
    int t;
    std::cin >> t;
    
    while (t--)
        solve();
}
```

</details>