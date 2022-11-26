# <center><u>[A. Love For Cricket](https://www.hackerrank.com/)</u></center>
---

Did you handle the case when $Q \leq 36$?

Each no ball gives you a free run and a free ball. Let us assume that Nikhilesh made bowler throw $x$ no balls. 

His score in that case will be:

Sum of runs scored in no balls + Sum of extra runs due to no balls + Sum of runs scored in non-no balls  $= x \cdot 6 + x \cdot 1 + 36$.

```math
\ \ \ \ \ \ \ x \cdot 6 + x \cdot 1 + 36 \geq Q

\newline

\implies x \cdot 7 \geq Q - 36

\newline

\implies \ x \geq \frac{Q - 36}{7}
```

$\therefore$  Minimum value of $x = ceil(\frac{Q - 36}{7})$.

Final ans = $max(0, min\_value\_of\_x)$

#### [CPP_Code](./../Codes//A_LoveForCricket.cpp)