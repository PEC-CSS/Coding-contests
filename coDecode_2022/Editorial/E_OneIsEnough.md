# <center><u>[E. Decrease To Zero](https://www.hackerrank.com/contests/codecode-pec/challenges/one-is-enough)</u></center>
---

<details>

<summary> Hint-1 </summary>

Is there any distinguishing feature that makes one positive integer different from other?

</details>

<details>

<summary> Hint-2 </summary>

Can we replace all positive integers with a particular number, say $p$ and all negative integers with a number, say $n$ and in the final state of array we can just count the number of $p$.

</details>

<details>

<summary> Hint-3 </summary>

**Exactly one** positive neighbour can make $A_i$ positive. Does this strike any bitwise operation in your mind. 

</details>

<details>

  <summary> Tutorial </summary>

We can choose $p = 1$ and $n = 0$. We can then do the bitwise operation I was talking in Hint-3. From now on, I will treat integer sequence $A$ as a binary integer sequence i.e., it contains only 0 and 1. 

If $A = (-2, -3, 4, 5, -6)$ we will first transform it into $A = (0, 0, 1, 1, 0)$ and then do further operations.

  <details>
  
  <summary> Hint-2 proof </summary>

- We see that both the operation only change sign on $A_i$ but the magnitude remains intact. Does changing magnitude of $A_i$ will have no effect.
Here, magnitude of $x$ = $ | x | $

  </details>

$A_i$ will become positive (or, $1$) if and only if it has exactly one positive neighbour, i.e. one of it's neighbour in transformed array will be $0$ and other will be $1$. From this, it is easy to see that if bitwise xor of neighbours of $A_i$ is $1$ then $A_i$ will become $1$ in next step.

Let us denote state of array after $i^{th}$ move as $C_i$ and $j^{th}$ of this array will be denoted as $C_{i, j}$.


$C_{1, i} = C_{0, i - 1} \oplus C_{0, i + 1}$, where $a \oplus b$ denotes bitwise xor of $a$ and $b$.

$C_{2, i} = C_{1, i - 1} \oplus C_{1, i + 1}$

$= (C_{0, i - 2} \oplus C_{0, i}) \oplus (C_{0, i} \oplus C_{0, i + 2})$

$= C_{0, i - 2} \oplus C_{0, i + 2}$, since $a \oplus a = 0$ and $0 \oplus a = a$.

For any $K$ which power of $2$

$C_{K, i} = C_{K,\ \ (i - K)\ \   mod\ \   N} \oplus C_{K,\ \  (i + K)\ \   mod\ \   N}$

In fact we can generalise it by saying,

$C_{J, i} = C_{J - K,\ \  (i - K)\ \ mod \ \ N} \oplus C_{J - K,\ \  (i + K)\ \  mod \ \  N}$   where $K$ is any integer that is power of $2$ and $J$ is any integer greater than $K$.

<details>

<summary> Follow up Question </summary>

- Can you prove why this would be the case if $K$ is not a power of $2$?

</details>

The next step is how do we generalise it for any $M$. It is easy to see that we can make jumps in power of $2$ to reach the needed state. Just write the number as sum of powers of two and make appropriate jumps.

`Example-1:` If $M = 10$ then we can first generate $C_2$ from $C_0$, then we can generate $C_{2 + 8}$ from $C_2$. 

`Example-2:`  For $M = 14$ we see that $(14)_{10} = (1110)_2$. Thus, we move in the following way:

  - Generate $C_2$ from $C_0$
  - Generate $C_{2 + 4}$ from $C_2$
  - Generate $C_{6 + 8}$ from $C_6$  

Since number of bits in a number $M$ is $log_2(M)$ so overall complexity will be $O(N \cdot log_2(M))$.

</details>

#### [`Setter CPP Code`](./../Codes/E_OneIsEnough.cpp)
#### [`Setter Python Code`](./../Codes/E_OneIsEnough_Python.py)
#### [`Tester CPP Code`](./../Codes/E_OneIsEnough_Tester.cpp)
