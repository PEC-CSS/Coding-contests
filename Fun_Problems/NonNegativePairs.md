# [2. Non Negative Pairs](https://www.hackerrank.com/contests/testing-1669399991/challenges/non-negative-pairs)

Do as instructed in problem but you cannot directly multiply $A_{i, j}$ and $A_{j, i}$ because it will go out of range of long long too. **BUT** you can use python, java inbuilt big-integers or use `__int128` in c++ to do so without getting any overflow problem. But these aren't the intended solution.

### Approach-1

---

- $A_{i, j} := signum(A_{i, j})$ where signum(x) is defined as following:
- $\operatorname{sgn}(x) = \begin{cases} 1 & x > 0 \\ 0 & x = 0 \\ -1 & x < 0 \end{cases}.$
- Now simply do as intructed in question, you will not face any overflow issue.

<details>

<summary>Code</summary>

```cpp
#include "bits/stdc++.h"

// Check #Problem-17 on discord server 
// if you do not understand implementation (Fun-Problem)
int signum(long long x)
{
    return (x > 0 ? 1 : x < 0 ? -1 : 0);
}

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector a(n, std::vector<long long>(m));
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
            valid_pairs += (signum(a[i][j]) * signum(a[j][i]) >= 0);
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

### Approach-2

---

- Do case work:
  - Let $A_{i, j} = x$ and $A_{j, i} = y$
  - If $(x \geq 0$ and $y \geq 0)$ or $(x \leq 0$ and $y \leq 0)$ then increase valid pair count otherwise do nothing.

<details>

<summary> Code </summary>

```cpp
#include "bits/stdc++.h"

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

### Approach-3

---

- Use bitwise xor $(\oplus)$
- If two non-zero numbers have opposite sign then their bitwise xor will be negative.
- If two non-zero number have same sign then their bitwise xor will be positive.
- The only problem is when one number is $0$ and other is some negative number say, $-x$. In this case bitwise xor becomes negative, You can handle this case separately.
- So for all bounded $(i, j)$, if $a_{i, j} = 0$ or $a_{j, i} = 0$ or $a_{i, j} \oplus a_{j, i} = 0$ then that pair is valid.


<details>

<summary> Code </summary>

```cpp
#include <bits/stdc++.h>

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
