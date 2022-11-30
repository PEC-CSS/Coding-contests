# <center><u>[C. Decrease to Zero](https://www.hackerrank.com/contests/codecode-pec/challenges/decrease-to-zero)</u></center>
---

The condition $0 < x*A_i ≤ A_i^2$ implies that $x$ can have any integer value from 0 to $|A_i|$ and its sign will be the same as the sign of $A_i$. In other words the sign of $A_i$ can be ignored and you can replace $A_i$ with $|A_i|$ for every $i$.

Now, if the array only contains 1's, then every time the player will choose it and make it zero. So, the answer will be dependent on the parity of n.

Else, the player getting a number > 1 for the first time wins the game.

<details>
    <summary>Why</summary>
    
Suppose, a player gets a number $x$ on his/her turn such that $x > 1$. Then, the player can make it either 1 or 0 to confirm his/her win.

`For Example` consider the following cases
Case 1: $A = [3, 1, 1, 1, 4, 5]$
* $[0, 1, 1, 1, 4, 5]$ Alice picks 3 
* $[0, 0, 1, 1, 4, 5]$ Bob is forced to pick 1
* $[0, 0, 0, 1, 4, 5]$ Alice picks 1
* $[0, 0, 0, 0, 4, 5]$ Bob is forced to pick 1 
* $[0, 0, 0, 0, 1, 5]$ Alice reaches a number with value $> 1$ again.
<!-- * $[0, 0, 0, 0, 0, 5]$ Bob is forced to pick 1 
* $[0, 0, 0, 0, 0, 0]$ Alice winds by picking 5 -->

So, the above sequence of operation shows that Alice can always find some set of moves that results her to jump from a number $> 1$ to another number $> 1$ by skipping odd number of $1s$.

Case 2: $A =  [3, 1, 1, 4, 5]$ 
* $[1, 1, 1, 4, 5]$ Alice picks 2
* $[0, 1, 1, 4, 5]$ Bob is forced to pick 1
* $[0, 0, 1, 4, 5]$ Alice picks 1
* $[0, 0, 0, 4, 5]$ Bob is forced to pick 1
* $[0, 0, 0, 1, 5]$ Alice reaches a number with value $> 1$ again.

Therefore, if there are even number of $1s$ between 2 numbers (both $> 1$) then the player can always find a way to jump from 1 to the other.

</details>