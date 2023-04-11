<div align = "center"><b><h1>Lockout v1</h1></b></div>

<div align="center"><b><h2>A. Sum of Good</h2></b></div>
<div align="center">Time Limit: 2 seconds</div>
<div align="center">Memory Limit: 512 MB</div>
<div align="center">input: standard input</div>
<div align="center">output: standard output</div>

<br>

Given a number $N$, write it as sum of good numbers.

A number is a good number if it contains exactly $1$ non-zero digit. $1$, $400$, $5000$ are good numbers but $6900$, $0$ and $11$ are not.

<h3>Input Format</h3>

- First line contains an integer $T$ - number of testcases
- Next $T$ lines contains a single integer $N$.

<h3> Constraints </h3>

- $1 \leq T \leq 10$
- $1 \leq N < 10^{101}$

<h3>Output Format</h3>

- For each testcase, print each good integer separated by space in descending order. It can be proved that the answer always exists and is unique.

<h3> Example </h3>

<h4>Input</h4>

```
2
69
420
```

<h4>Output</h4>

```
60 9
400 20
```