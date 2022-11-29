# <center><u>[F. TLE or MLE](https://www.hackerrank.com/contests/codecode-pec/challenges/harasees-is-asleep)</u></center>
---

<details>
  <summary>Hint 1</summary>
  
  Even if you add up all the differences, the final sum 
  $\le A_n$. 
  </details>
<details>
  <summary>Hint 2</summary>
  
  Can you place an upper bound on the number of unique differences ?
</details>
<details>
  <summary>Hint 3</summary>
  
   
  The number of unique differences is bounded by $O(\sqrt A_n)$.
</details>
<details>
  <summary>Tutorial</summary>
  
  We can calculate all the differences and use standard knapsack to to solve the problem. But this will result in TLE or MLE depending upon your implementation. 

  Note that the number of unique values of differences is bounded by $O\sqrt A_n$. 

  <details>
  <summary>Why</summary>
  
  The sum of first $N$ natural number is of the order of $O(N^2)$. In other words if $p$ distinct positive numbers sum up to a number $N$ then $p$ is $O(N)$
</details>
  
  Let us name the distinct differences array as $perm$ and corresponding occurrences as $cnt$. Let $dp(i,j)$ be the minimum number of differences required to form sum = $j$ using differences from indices $(1,i)$ where $1≤i≤perm.size()$.

  Hence, in order to calculate $dp(i,j)$ (where $i$ is the index of the current value $x$ being processed and $j$ is the cost), we only need these states $dp(i−1,j−x),dp(i−1,j−2×x),…,dp(i−1,j−cnt(i)×x)$. For each distinct difference, store its number of occurrences and then the idea is to treat it like a <u>[sliding window minimum](https://wcipeg.com/wiki/Sliding_range_minimum_query)</u> problem.

  Hence, the recurrence becomes $dp(i,j) = min(v + dp(i − 1, j − v×perm[i]), \ v ∈ [0, cnt(i)]$

  Then, if we consider the values $j\ mod \ k$, you will notice that for a fixed remainder it just becomes a range min query on a 'sliding window' interval (namely, the left bound of the interval may only move to the right each query), which can be computed in amortized constant time using a monotonic deque.

  Complexity will be $O(A_n \sqrt A_n)$ to populate the dp table and $O(m)$ to answer all the $m$ queries. 
</details>