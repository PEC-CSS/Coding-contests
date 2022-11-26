# <center><u>[A. Love For Cricket](https://www.hackerrank.com/)</u></center>
---

Did you handle the case when $Q \leq 36$?

Each no ball gives you a free run and a free ball. Let us assume that Nikhilesh made bowler throw $x$ no balls. 

His score in that case will be sum of runs scored in no balls + sum of extra runs due to no balls + sum of runs scored in non-no balls $= x \cdot 6 + x \cdot 1 + 36$.

$\ \ \ \ \ \ \ x \cdot 6 + x \cdot 1 + 36 \geq Q$
$or, \ x \cdot 7 \geq Q - 36$
$or, \ x \geq \frac{Q - 36}{7}$

Minimum value of $x = ceil(\frac{Q - 36}{7})$.