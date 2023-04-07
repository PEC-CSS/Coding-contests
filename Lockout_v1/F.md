<div align = "center"><b><h1>Lockout v1</h1></b></div>

<div align="center"><b><h2>F. Double Chance</h2></b></div>
<div align="center">Time Limit: 2 seconds</div>
<div align="center">Memory Limit: 512 MB</div>
<div align="center">input: standard input</div>
<div align="center">output: standard output</div>

<br>

There are $N$ cards card $1$, card $2$, $\ldots$, card $N$. On card $i$ $(1 \leq i \leq N)$, an integer $A_i$ is written.

for $K = 1, 2, \ldots, N$, solve the following problem.

> We have a bag that contains $K$ cards: card $1$, card $2$, $\ldots$, card $K$.
Let us perform the following operation twice, and let $x$ and $y$ be the numbers recorded, in the recorded order.
> > Draw a card from the bag uniformly at random, and record the number written on that card. Then, return the card to the bag.

Print the expected value of $\max(x, y)$, modulo $998244353$.

Here $\max(x, y)$ denoted the value of the greater of $x$ and $y$ (or $x$ if they are equal).

<h3>Input Format</h3>

- First line contains an integer $N$ - number of cards
- Second line contains $N$ space separated integers $A_i$ - number written on card $i$.

<h3> Constraints </h3>

- $1 \leq N \leq 2 \times 10^5$
- $1 \leq A_i \leq 2 \times 10^5$

<h3>Output Format</h3>

- Print $N$ lines. The $i-th$ line $(1 \leq i \leq N)$ should contain the answer to the problem for $K = i$.

<h3> Example </h3>

<h4>Input</h4>

```
3
5 7 5
```

<h4>Output</h4>

```
5
499122183
443664163
```

<h4> Explanation </h4>

For instance, the answer for $K=2$ is found as follows.

The bag contains card $1$ and card $2$, with $A_1 = 5$ and $A_2 = 7 written on them, respectively.

- If you draw card $1$ in the first draw and card $1$ again in the second draw, we have $x=y=5$, so $\max(x,y)=5.$
- If you draw card $1$ in the first draw and card $2$ in the second draw, we have $x=5$ and $y=7$, so $\max(x,y)=7.$
- If you draw card $2$ in the first draw and card $1$ in the second draw, we have $x=7$ and $y=5$, so $\max(x,y)=7.$
- If you draw card $2$ in the first draw and card $2$ again in the second draw, we have $x=y=7$, so $\max(x,y)=7.$

These events happen with the same probability, so the sought expected value is $\frac{5+7+7+7}{4} = \frac{13}{2}$. We have $499122183×2 \equiv 13\ (\text{mod} \ 998244353)$, so $499122183$ should be printed.

<h4>Input</h4>

```
7
22 75 26 45 72 81 47
```

<h4>Output</h4>

```
22
249561150
110916092
873463862
279508479
360477194
529680742
```
