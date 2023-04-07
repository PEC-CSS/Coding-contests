<div align = "center"><b><h1>Lockout v1</h1></b></div>

<div align="center"><b><h2>B. Coins of TypeZer0</h2></b></div>
<div align="center">Time Limit: 2 seconds</div>
<div align="center">Memory Limit: 512 MB</div>
<div align="center">input: standard input</div>
<div align="center">output: standard output</div>

<br>

Utkarsh Goel has two types of coins namely, **TypeZer0** and **Type1** <strike>no pun intended</strike>. He wants to place coins one by one from left to right.

Initially, there is no coin placed. He performs the following operation $10^{100}$ times:

- Place $X$ **"TypeZer0"** coins at the end of the row of coins already placed and then place $Y$ **"Type1"** coins at the end of the row.

Now, he is interested in finding out the number of **"TypeZer0"** coins among the first $N$ coins in the row of balls made this way.

<h3>Input Format</h3>

- First line contains three integers $N,\ X,\ Y$ - All of them are described in problem statement.

<h3> Constraints </h3>

- $1 \leq N \leq 10^{18}$
- $X + Y \leq 10^{18}$
- $X, Y \geq 0$

<h3>Output Format</h3>

- Print a single integer denoting number of **"TypeZer0"** coins among the first $N$ coins in the row of coins.

<h3> Examples </h3>

<h4>Input</h4>

```
10 4 0
```

<h4>Output</h4>

```
10
```

<h4> Explanation </h4>

- Since, utkarsh is not placing any **Type1** coin so number of **TypeZer0** coins among the first $10$ coins will be $10$.

<h4>Input</h4>

```
10 4 2
```

<h4>Output</h4>

```
8
```

<h4> Explanation </h4>

-  First $10$ coins looks like this: $0000110000$. Thus, answer is $8$.

<h4>Input</h4>

```
10 4 3
```

<h4>Output</h4>

```
7
```

<h4> Explanation </h4>

- First $10$ coins look like $0000111000$. Thus, the answer is $7$.
