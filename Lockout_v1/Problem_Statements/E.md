<div align = "center"><b><h1>Lockout v1</h1></b></div>

<div align="center"><b><h2>E. Divide the bread</h2></b></div>
<div align="center">Time Limit: 2 seconds</div>
<div align="center">Memory Limit: 512 MB</div>
<div align="center">input: standard input</div>
<div align="center">output: standard output</div>

<br>

We have a loaf of bread of length $L$, which we will cut and distribute to $N$ children. The $i-th$ child $(1 \leq i \leq N)$ wants a loaf of length **exactly** $A_i.$

Now, Arjun will repeat the operation below to cut the loaf into lengths $A_1, A_2, \ldots, A_N$ for the children:

Choose a loaf of length $k$ and an integer $x$ between $1$ and $k - 1$ (inclusive). Cut the loaf into two loaves of length $x$ and $k - x$. This operation incurs cost of $k$ regardless of the value of $x$.

Each child $i$ must receive a loaf of length **exactly** $A_i$, but it is allowed to leave some loaves undistributed.

Find the minimum cost needed to distribute loaves to all children.

<h3>Input Format</h3>

- First line contains two integers $N$ and $L$ - number of children and loaf of bread.
- Second line contains $N$ space separated integer - length of loaf each children want.

<h3> Constraints </h3>

- $2 \leq N \leq 2 \times 10^5$
- $1 \leq A_i \leq 10^9$
- $\sum_{i = 1}^{n} A_i \leq L \leq 10^5$

<h3>Output Format</h3>

- Print the minimum cost needed to distribute loaves to all children.

<h3> Example </h3>

<h4>Input</h4>

```
5 7
1 2 1 2 1
```

<h4>Output</h4>

```
16
```

<h4> Explanation </h4>

Takahashi can cut the loaf for the children as follows.

- Choose the loaf of length $7$ and $x = 3$, cutting it into loaves of length $3$ and $4$ for a cost of $7$.
- Choose the loaf of length $3$ and $x=1$, cutting it into loaves of length $1$ and $2$ for a cost of $3.$ Give the former to the $1-st$ child.
- Choose the loaf of length $2$ and $x=1$, cutting it into two loaves of length $1$ for a cost of $2.$ Give them to $3-rd$ and $5-th$ child.
- Choose the loaf of length $4$ and $x=2$, cutting it into two loaves of length $2$ for a cost of $4.$ Give them to $2-nd$ and $4-th$ child.

This incurs a cost of $7 + 3 + 2 + 4 = 16$, which is minimum possible. There will be no leftovers loaves **in this case**.

<h4>Input</h4>

```
3 1000000000000000
1000000000 1000000000 1000000000
```

<h4>Output</h4>

```
1000005000000000
```