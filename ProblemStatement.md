<a href="https://www.hackerrank.com/contests/lockout-v2-pec-acm/challenges">
    <h1 style="color: #5cafff">
        <img style="float: left" src="./../../asset/acm_logo.png" width=80> 
        <p align="center">
            Lockout v2
        </p>
    </h1>
</a>

<a href="#" align="https://www.hackerrank.com/contests/lockout-v2-pec-acm/challenges/kcd" style="color: white">
    <h2 align="center"> A. KCD </h2>
</a>

<p align="center"> 
    <span style="font-size: 17px"> <span style="font-weight: 600">Score: 100 </span> <br>
    <span style="font-weight: 500">Time Limit per test:</span> 2 seconds <br>
    <span style="font-weight: 500">Memory Limit per test:</span> 512 MB <br>
</p>

You are given two positive integers $A$ and $B$.

Find the $K^{th}$ largest positive integer that divides both $A$ and $B$. 

It is guaranteed that $K \leq \text{total number of common divisors of}\ A\ \text{and}\ B$.

<h3> Input Format </h3>

- First line of input contains three integers $A$, $B$ and $K$.

<h3> Constraint </h3>

- $1 \leq A,\ B \leq 100$
- $K \geq 1$
- $K \leq \text{total number of common divisors of}\ A\ \text{and}\ B$

<h3> Output Format </h3>

- Print the $K^{th}$ largest common divisor of $A$ and $B$.

<h3> Sample Input 1 </h3>

```
8 12 2
```

<h3> Sample Output 2 </h3>

```
2
```
- Common divisor of $8$ and $12$ are $(1, 2, 4)$. $2$ is second largest among them.

<h3> Sample Input 2 </h3>

```
1 1 1
```

<h3> Sample Output 2 </h3>

```
1
```

<h3> Sample Input 3 </h3>

```
55 89 1
```

<h3> Sample Output 3 </h3>

```
1
```

<br>
<br>
<a href="https://www.hackerrank.com/contests/lockout-v2-pec-acm/challenges/find-ranks" align="center" style="color: white">
    <h2 align="center"> B. Find Ranks </h2>
</a>

<p align="center"> 
    <span style="font-size: 17px"> <span style="font-weight: 600">Score: 300 </span> <br>
    <span style="font-weight: 500">Time Limit per test:</span> 2 seconds <br>
    <span style="font-weight: 500">Memory Limit per test:</span> 512 MB <br>
</p>

There are $2^{N}$ players. The $i^{th}$ player has a power of $A_i$. If two players $i$ and $j$ fight, then the player having greater power wins.

**For example:** If player-$1$ has a power $2$ and player-2 has a power of $1$, then player-$1$ will defeat player-$2$ in fight.

We are holding a knockout tournament between all $2^N$ players. The fights will take place between players from left to right, player-$i$ will fight player-$(i + 1)$, player-$(i + 2)$ will fight player-$(i + 3)$ and so on. It goes on until only $1$ player remain. See image below for more clarity.

If a player loses in round-$X$ then his rank will be $N + 2 - X$. If he never loses, his rank is $1$.

You task is to find rank of each player. It is guaranteed that power of each player is unique and is greater than equal to $1$ and no more than $2^N$

<h3> Input Format </h3>

- First line contains a single integer $T$ - Number of testcases.
- Next two lines of each testcase contains:
  - A single integer $N$ - Denoting $log_2(\text{Total number of players})$, since $2^N$ players are in tournament.
  - $2^N$ space separated integers where $i^{th}$ integer denotes $A_i$ - Power of each player. 

<h3> Constraint </h3>

- $1 \leq T \leq 100$
- $1 \leq N \leq 10$
- $1 \leq A_i \leq 2^N$
- $A$ is a permutation of $2^N$ 

**NOTE:** A permutation is a sequence of integers from 1 to $N$ of length $N$ containing each number exactly once. 

<h3> Output Format </h3>

- For each testcase print $2^N$ space separated integer, where $i^{th}$ integer denote rank of $i^{th}$ player.

<h3> Sample Input 1 </h3>

```
1
2
3 2 1 4
```

<h3> Sample Output 1 </h3>

```
2 3 3 1
```

Following image shows how the tournament goes:

![tournament-sample](../../asset/lockout_v2/findRank-sample1.png)

<br>
<br>
<a href="https://www.hackerrank.com/contests/lockout-v2-pec-acm/challenges/one-second-please" align="center" style="color: white">
    <h2 align="center"> C. one_second Please </h2>
</a>

<p align="center"> 
    <span style="font-size: 17px"> <span style="font-weight: 600">Score: 300 </span> <br>
    <span style="font-weight: 500">Time Limit per test:</span> 2 seconds <br>
    <span style="font-weight: 500">Memory Limit per test:</span> 512 MB <br>
</p>

*While fleeing from police Om goes to NSS Ground and finds a sequence. So he decided to play a game with the  police.*

Om and Police have an integer sequence $A$ of length $N$. If Om wins the game he gets to be free from police, otherwise he will be captured.

Let number of triplets $(i, j, k)$ such that $i < j < k$ and $A_i = A_j$ and $A_j = A_k$ be $X$, and $Y$ be the number of remaining triplets.

- If $X \geq Y$, then Om wins the game.
- If $Y > X$, then police wins the game.

Om has **"one second"** <strike>(no pun intended :p)</strike> in which he can change atmost $K$ integers of the sequence to any integer of his choice.

**For example:** If $A = (1, 2, 3, 4)$ and $K = 2$, then Om can change any two elements of $A$. One possible such array is $A = (1, 1, 1, 4)$

<h3> Input Format </h3>

- First line contains an integer $T$ - Number of testcase.
- Next two lines of each testcase contains:
  - Two integers $N$ and $K$ - Length of integer sequence and number of integer Om can change in one second.
  - $N$ space separated integers where $i^{th}$ integer denotes $A_i$.

<h3> Constraint </h3>

- $1 \leq T \leq 1000$
- $1 \leq K \leq N \leq 2 \cdot 10^5$
- $1 \leq A_i \leq 10^9$
- Sum of $N$ over all testcase does not exceed $10^6$, i.e. $(\sum_{i = 1}^{T} N) \leq 10^6$

<h3> Output Format </h3>

- For each testcase print "YES" if Om keeps the sequence, "NO" otherwise. 

**NOTE:** Assume checker to be **Case sensitive**, i.e., "Yes", "YES" are treated differently.

<h3> Sample Input 1 </h3>

```
2
3 1 
1 2 3
3 2
1 2 1
```

<h3> Sample Output 1 </h3>

```
NO
YES
```

- It can be shown that no matter what Om does, Abhilash will win and thus keep the sequence.
- Om can convert the sequence to $A = (2, 2, 2)$, this way he will have $1$ equal triplet and Abhilash will have $0$, Thus, he can keep the sequence.

<br>
<br>
<a href="https://www.hackerrank.com/contests/lockout-v2-pec-acm/challenges/couple-messiah-ac" align="center" style="color: white">
    <h2 align="center"> D. Couple Messiah - AC </h2>
</a>

<p align="center"> 
    <span style="font-size: 17px"> <span style="font-weight: 600;">Score: 400 </span> <br>
    <span style="font-weight: 500">Time Limit per test:</span> 2 seconds <br>
    <span style="font-weight: 500">Memory Limit per test:</span> 512 MB <br>
</p>

**Abhilash - The Messiah of IIT Jodhpur couples**, decided to visit the college. After going to college he found out that students are randomly paired up and made to sit together, to not allow couple to hold hands.

But wait, this is not as good as it sounds because IIT Jodhpur has $N$ couples and a total of $2 \cdot N$ students **only**, which means nobody is single :'( 

Abhilash being their messiah decides to make couples sit together so they can hold hands. The couples are numbered in order, the first couple being $(0, 1)$, the second couple being $(2, 3)$, and so on with the last couple being $(2\cdot N - 2, 2\cdot N - 1)$.  In $1$ minute, he can make two people swap their places. See sample explanation for more clarity. 

Find minimum time (in minutes) needed by Abhilash to make all couples sit adjacent to each other so they can _hold hands_

<h3> Input Format </h3>

- First line contains an integer $T$ - Number of testcase.
- Next two lines of each testcase contains:
  - An integer $N$ - Number of couples.
  - $2 \times N$ space separated integer denoting couple id of each couple.

<h3> Constraint </h3>

- $1 \leq T \leq 1000$
- $1 \leq N \leq 2 \times 10^5$
- $\text{couple id of each person is unique and is between}\ 0\ \text{and}\ (2 \cdot N - 1)$
- Sum of $N$ over all testcase does not exceed $10^6$ - $\sum_{i = 1}^{T} N \leq 10^6$

<h3> Output Format </h3>

- Print a single integer denoting minimum number of minutes Abhilash would need **to make each couple sit side by side.**

---

<h3> Disclaimer </h3>

- No harm or disrespect is intended towards any college or university. Any mentions of specific institutions do not reflect any personal views or opinions.
- While Abhilash **may** have a reputation for being a relationship guru, we cannot guarantee that he is, in fact, the messiah of all the couples.

<h3> Sample Input 1 </h3>

```
2
3
0 1 2 3 4 5
2
0 2 1 3
```

<h3> Sample Output 1 </h3>

```
0
1
```

- In first case, all couples are already together.
- In second case, Abhilash can do $1$ swap to make all couples sit together as shown in the image below.

![sample01](./../../asset/lockout_v2/coupleMessiahAC-sample1.png)

<br>
<br>
<a href="https://www.hackerrank.com/contests/lockout-v2-pec-acm/challenges/how-many-lcms" align="center" style="color: white">
    <h2 align="center"> E. How many LCMs? </h2>
</a>

<p align="center"> 
    <span style="font-size: 17px"> <span style="font-weight: 600;">Score: 500 </span> <br>
    <span style="font-weight: 500">Time Limit per test:</span> 2 seconds <br>
    <span style="font-weight: 500">Memory Limit per test:</span> 512 MB <br>
</p>

You have an integer sequence $A = (A_1, A_2, \cdots, A_N)$ of length $N$.

You perform $N$ operations:

- In $i^{th}$ operation you change $A_i$ to $1$ and then add the LCM of the sequence $A$ into set $S$.
- You revert $A_i$ back to it's original value and continue with next operation.

You need to tell the number of distinct element in set $S$.

---

#### **NOTE on input format of  $A_i$:** 

You will given prime factorisation of $A_i$ in the following format:

- First you will be given an integer $m_i$ denoting, how many prime numbers are in $A_i$'s prime factorisation.
- Then next $m_i$ lines willcontain two space separated integers $p_{i, j},$ $e_{i, j}$ denoting it's $j^{th}$ prime factor and it's power. 

More formally, $A_i = p_{i, 1}^{e_{i, 1}} \times p_{i, 2}^{e_{i, 2}} \times \cdots \times p_{i, m_i}^{e_{i, m_i}}$, where $p_{i, 1} < p_{i, 2} < \cdots < p_{i, m_i}$ and all $e_{i, j} > 1$. 

<h3> Input Format </h3>

- First line contains a single integer $N$ - Number of integers in sequence.
- Next all lines contains prime factorisation of $A_i$ which follows the following format:
  - $m_{i}$ - Number of prime factors of $A_i$
  - $p_{i, 1},\ \ e_{i, 1}$ 
  - $p_{i, 2},\ \ e_{i, 2}$
  - $...$
  - $p_{i, m_i},\ \ e_{i, m_i}$

<h3> Constraint </h3>

- $1 \leq N \leq 2 \cdot 10^5$
- $m_i \geq 1$
- $\sum m_i \leq 2 \cdot 10^5$
- $2 \leq p_{i, 1} < p_{i, 2} < \cdots < p_{i, m_i} \leq 10^9$
- $p_{i, j}$ is a prime number.
- $e_{i, j} \geq 1$

<h3> Output Format </h3>

- Print a single integer denoting the answer - Number of distinct element in the set $S$.

<h3> Sample Input 1 </h3>

```
4
1
7 2
2
2 2
5 1
1
5 1
2
2 1
7 1
```

<h3> Sample Output 1 </h3>

```
3
```

Initially, $A = (49, 20, 5, 14)$

- After $1^{st}$ operation $A = (1, 20, 5, 14):\ \text{LCM(A)} = 140.$ 
- After $2^{nd}$ operation $A = (49, 1, 5, 14):\ \text{LCM(A)} = 490.$ 
- After $3^{rd}$ operation $A = (49, 20, 1, 14):\ \text{LCM(A)} = 980.$ 
- After $4^{th}$ operation $A = (49, 20, 5, 1):\ \text{LCM(A)} = 980.$ 

Thus $S = \{140, 490, 980, 980\}$. Number of distinct elements are 3.

<h3> Sample Input 2 </h3>

```
1
1
998244353 1000000000
```

<h3> Sample Output 2 </h3>

```
1
```

<h3> Sample Input 3 </h3>

```
2
1
3 7
3
3 10
5 6
11 1
```

<h3> Sample Output 3 </h3>

```
2
```

<br>
<br>
<a href="https://www.hackerrank.com/contests/lockout-v2-pec-acm/challenges/minimise-aad" align="center" style="color: white">
    <h2 align="center"> F. Minimise Absolute Difference </h2>
</a>

<p align="center"> 
    <span style="font-size: 17px"> <span style="font-weight: 600;">Score: 600 </span> <br>
    <span style="font-weight: 500">Time Limit per test:</span> 2 seconds <br>
    <span style="font-weight: 500">Memory Limit per test:</span> 512 MB <br>
</p>

You are given a integer $K$ and an integer sequence $A = (A_1, A_2, ..., A_N)$ of length $N$ in which each element is atmost $M$.

You can do the following operation atmost $K$ times:

Select any integer $i$ $(1 \leq i \leq n)$ and change $A_i$ to any positive integer $x$.

You have to minimise the value of $max(| h_{i + 1} - h_i |),$   $\ \forall i$ $(1 \leq i < n)$.

<h3> Input Format </h3>

- The first line of input contains one integer $T$ $-$ the number of test cases.
- The second line contains three integers $N, M$ and $K$ $-$ length of sequence and maximum numbers of operation allowed.
- The third line contains $N$ integers $A_1, A_2, ..., A_N$ $-$ the integer sequence.

<h3> Constraint </h3>

- $1 \leq T \leq 10^4$
- $0 \leq K < N$ 
- $2 \leq N \leq 500$
- $1 \leq M \leq 1000$
- $1 \leq A_i \leq M$
- It is guaranteed that sum of $N \cdot M$ over all test cases does not exceed $10^6$.

<h3> Output Format </h3>

Print a single integer denoting the minimum value of $max(| h_{i + 1} - h_i |),$   $\ \forall i$ $(1 \leq i < n)$.

<h3> Sample Input 1 </h3>

```
4
5 10 0
1 2 1 3 1
5 7 3 
1 3 5 3 1
6 10 0
1 4 7 1 4 7
7 10 4 
1 5 8 5 5 7 8
```

<h3> Sample Output 1 </h3>

```
2
0
6
0
```

- In the first test case you cannot make any changes. Difference array, $D = (|1 - 2|, |2 - 1|, |1 - 3|, |3 - 1|) = (1, 1, 2, 2)$. Thus, answer is $2$.
- In fourth test case. You can change $A_1, A_3, A_6, A_7$ to $5$. $A = (5, 5, 5, 5, 5, 5, 5)$. Difference array, $D = (0, 0, 0, 0, 0, 0)$ Thus the answer is $0$.

