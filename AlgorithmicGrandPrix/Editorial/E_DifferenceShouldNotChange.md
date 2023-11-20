# <center><u>[E. Difference Should Not Change](https://www.hackerrank.com/contests/algorithmic-grand-prix-pecfest2023/challenges/difference-should-not-change)</u></center>
---

The problem can be reworded as divide elements $A$ into two subsequence (every element is a part of exactly $1$ subsequence) such that both of them are in Arithematic Progression. 

We have three starting points for one of the AP:
1. $B = (A_1, A_2, \cdots)$
2. $B = (A_1, A_3, \cdots)$
3. $B = (A_2, A_3, \cdots)$

If we take $B = (A_1, A_4, \cdots)$ then $C = (A_2, A_3, \cdots)$, which is just case-$3$. Let us see how to check whether we can divide $A$ into two parts by following case-$1$, one can try for other two cases in similar fashion.

Our algorithm goes as follows:
1. Since first $2$ elements of $B$ is fixed so we know the common difference of AP. Form the biggest sequence $B$. The elements which cannot be added in $B$ should be added in $C$.
2. If $C$ is already in AP, we terminate
3. Otherwise, we need to remove some elements from $B$ and add it somewhere in $C$ so it forms a AP. To do so, we can only remove a complete suffix of $B$, since removing element from middle will change common difference of AP, which will be covered in some other case already.
4. Let us take the difference of adjacent elements of $C = (d_1, d_2, \cdots, d_k)$. The common difference for $C$ should be $g = \gcd(d_1, d_2, \cdots, d_k)$. If it is not possible to form an arithmetic progression (AP) with the common difference $g$, then it is not possible to form an AP with any other value of the common difference.
5. Find the smallest element that is missing in $C$. Now find that element in $B$, if you cannot find then you cannot divide $A$ otherwise you have to fit all elements of $B$ from index of that minimum element to end.

If you cannot form AP in any of the three case then you cannot divide $A$, otherwise you get the answer.