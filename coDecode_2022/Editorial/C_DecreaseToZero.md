# <center><u>[C. Decrease to Zero](https://www.hackerrank.com/contests/codecode-pec/challenges/decrease-to-zero)</u></center>
---
The condition $0 < X*A_i ≤ A_i^2$ implies that X can have any integer value from 0 to $abs(A_i)$ and its sign will be the same as the sign of $A_i$.

Now, if the array only contains 1's, then every time the player will choose it and make it zero. So, the answer will be dependent on the parity of n.

Else, the player getting a number > 1 for the first time wins the game.

<details>
    <summary>Why</summary>
    
Suppose, a player gets a number $x$ on his/her turn such that $x > 1$. Then, the player can make it either 1 or 0 to confirm his/her win.

For example consider the following cases
Case 1: A = [3, 1, 1, 1, 4, 5] -> [0, 1, 1, 1, 4, 5] -> [0, 0, 1, 1, 4, 5] -> [0, 0, 0, 1, 4, 5] -> [0, 0, 0, 0, 4, 5] -> [0, 0, 0, 0, 1, 5] -> [0, 0, 0, 0, 0, 5] -> [0, 0, 0, 0, 0, 0]
So, the above sequence of operation shows that Alice wins when there are an odd number of 1's after $x$

Case 2: A =  [3, 1, 1, 4, 5] -> [1, 1, 1, 4, 5] -> [0, 1, 1, 4, 5] -> [0, 0, 1, 4, 5] -> [0, 0, 0, 4, 5] -> [0, 0, 0, 1, 5] -> [0, 0, 0, 0, 5] -> [0, 0, 0, 0, 0]
Again Alice wins, even though there were even number of 1's after $x$.
</details>