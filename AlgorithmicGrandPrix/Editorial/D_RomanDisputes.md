# <center><u>[D. Roman disputes](https://www.hackerrank.com/contests/algorithmic-grand-prix-pecfest2023/challenges/roman-disputes)</u></center>
---

Initially number of soldiers in each legion is $X$. Let number of dispute in which $i^{th}$ sent it's soldiers be $D_i$. Our aim is to minimimse $\sum_{i = 1}^{N} D_i$. We have $N$ equations now:

$$
A_i + D_i \cdot Z = X, \text{ where } 1 \leq i \leq N
$$
$$
\implies Z = \frac{X - A_i}{D_i}
$$

### Case-1: $X = \max(A)$:
---

To minimise number of disputes $\sum_{i = 1}^N D_i$, we must maximise $Z$. 

Since $Z$ divides $X - A_i$ for all $1 \leq i \leq N$, so maximum value of $Z = \gcd(X - A_1, X - A_2, \cdots, X - A_N)$. 

### Case-2: $X > \max(A)$:
---

Let $X = \max(A) + E$. In this case $Z = \gcd(X - A_1, X - A_2, \cdots, X - A_N)$. Let us call $Z$ from case-$1$ as $Z_1$ and from this case as $Z_2$.

If $E$ is divisible by $Z_2$ then $Z_2 = \gcd(X - E - A_1, \cdots, X - E - A_N)$ is divisible by $Z_1 = \gcd(\max(A) - A_1, \cdots, \max(A) - A_N)$. Thus $Z_1 \geq Z_2$, so case-$1$ is better.

To complete the proof, we show that $E$ is always divisible by $Z_2$. We know that $X - A_i$ is divisible by $Z_2$ for all $1 \leq i \leq N$, thus $(X - \max(A)) = E$ is also divisible by $Z_2$.