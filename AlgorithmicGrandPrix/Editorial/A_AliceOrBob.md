# <center><u>[A. Alice or Bob](https://www.hackerrank.com/contests/algorithmic-grand-prix-pecfest2023/challenges/alice-or-bob)</u></center>
---

<!-- Let us see how Alice can get the best numbers to submit:
- Keep subtracting $B$ from $A$ unless $A - B$ is negative. This gives you the best non-negative number. 
  - You can find this $K$ by binary search (maximum $K$ for which $A - K \cdot B \geq 0$).
  - You can also directly find the value of $A - K \cdot B$ value by doing $A \mod B$, where $A \mod B$ denote the remainder when $A$ is divided by $B$. 
- Keep subtracting $B$ from $A$ until $A$ becomes negative for the first time.
  - You can find this $K$ by binary search too (Find minimum $K$ such that $A - K \cdot B < 0$).
  - You can also directly find the value of $|A - K \cdot B|$ by doing $B - A \mod B$. 

Thus, we conclude that the best value Alice can submit to computer is $C = \min(A \mod B,\ B - A \mod B)$. -->

Let us assume the best value Alice can submit is $C$. Now, Bob has to submit $-C$ to draw the game since he cannot choose the same number as Alice which gives us two equations:
  - $A - K_1 \cdot B = C$  
  - $A - K_2 \cdot B = -C$
  
## Solution-1

After solving we only need to verify whether the two numbers are same or not, if they are not same then Bob can draw the game, else Bob cannot.

The best non-negative value for $C$ is $A \mod B$ where $A\mod B$ denote the remainder when $A$ is divided by $B$, and the best negative value is $(A\mod B) - B$. Thus $C = \min(A \mod B, -(A \mod B - B))$.

<details>

<summary> Example for (B - A mod B) </summary>

Take $A = 5$ and $B = 3$, here $A\mod B = 2$ but Alice can take $K = 2$ and thus can submit $-1$ to computer, which has lesser absolute value than $2$.

</details>

## Solution-2

One can also binary search to find the best positive and negative value of $C$.

- For best non-negative value, you have to find the maximum $K$ for which $A - K \cdot B \geq 0$.
- For best non-positive value, you have to find the minimum $K$ for which $A - K \cdot B \leq 0$.

**Bonus:** Can you think of a even simpler and shorter solution than the above two?