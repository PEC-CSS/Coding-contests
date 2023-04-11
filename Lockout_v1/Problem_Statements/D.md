<div align = "center"><b><h1>Lockout v1</h1></b></div>

<div align="center"><b><h2>D. Optimistic Please (Hard Version)</h2></b></div>
<div align="center">Time Limit: 2 seconds</div>
<div align="center">Memory Limit: 512 MB</div>
<div align="center">input: standard input</div>
<div align="center">output: standard output</div>
<br>

*The only difference between the easy and hard version of this problem is the constraints on* $N$ and $A_i$

---

There are $N$ people in a room standing in a line. Each person has some positivity value associated with him/her. Positivity of person-$i$ is denoted by integer $A_i$.

- Positive value of positivity suggest that the person is more optimistic than pessimistic.
- Negative value of positivity suggest that the person is more pessimistic than optimistic. 
- $0$ positivity suggest that the person is neither optimistic and nor pessimistic.

You want to know the **number of ways** to make an **optimistic group** containing $1$ or more people by making some people from front and some people from back of line leave the room. 

More formally, If person $x$ and person $y$, (where $x$ is the least person number and $y$ is the max person number chosen) are a part of group then person $(x + 1), (x + 2), ..., (y - 1)$ must also be a part of your group.

A group is said to be optimistic if the **sum of positivity values of all person of the group is positive**.

<h3>Input Format</h3>

- First line contains an integer $N$ - number of persons in the room.
- Second line contains $N$ space separated integers - Positivity of person-$i$ in the room.

<h3> Constraints </h3>

- $1 \leq N \leq 2 \times 10^{5}$
- $-10^9 \leq A_i \leq 10^9$

<h3>Output Format</h3>

- Print a single integer representing answer.

<h3> Examples </h3>

<h4>Input</h4>

```
3
1 -1 2 
```

<h4>Output</h4>

```
4
```

<h4> Explanation </h4>

- Following $4$ groups can be chosen:
  
  - person-$1$ 
  - person-$3$
  - person-$2$ and person-$3$
  - person-$1$, person-$2$ and person-$3$

<h4> Input </h4>

```
3
0 1 3 
```

<h4> Output </h4>

```
5
```