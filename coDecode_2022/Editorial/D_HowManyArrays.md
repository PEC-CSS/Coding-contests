# <center><u>[D. How Many Arrays](https://www.hackerrank.com/contests/codecode-pec/challenges/how-many-arrays-iswar-charmi)</u></center>
---

<details>
  <summary>Hint 1</summary>
  Rearrange the odd and even indices
</details>
<details>
  <summary>Hint 2</summary>

  Think of the array $A_1, A_3, A_5, ..., A_{2 \cdot n - 1}, A_2, A_4, ..., A_{2 \cdot n}.$ How many such arrays are possible ? The answer to this problem is the answer to the original problem.

</details>
<details>
  <summary>Tutorial</summary>

  The number of $N$ length arrays which are non-decreasing and have elements in the range $[1, M]$ is $^{N + M - 1} C_{M - 1}$ Where $^N C_R$ is the number of possible combinations of $R$ elements given $N$ elements.

  <details>
    <summary>Why</summary>

    Assume that you have $N$ numbers and you wish to group them in $M$ partitions. A partition is allowed to be empty. The $i^{th}$ partition from the left will have all it's elements equal to $i$. The number of such partitions is the number of ways of inserting $M - 1$ 'bars' among the $N$ numbers. Each bar shall act as a separation between $2$ partitions. This can be solved by assuming a total of $N + M - 1$ elements and selecting $M - 1$ elements out of them. The selected elements become 'bars' and rest of the $N$ elements act as numbers.

  </details>


  Notice that each non-decreasing array uniquely maps to exactly $1$ array satisfying the constraints given in the problem statement. To create such an array, simply reverse the second half of the non-decreasing array and then zip the first half and second half together such that all the elements in the second half occupy all the even indices while the elements of the first half occupy the odd indices.

  Example: $(1, 2, 3, 4)$ will map to $(1, 4, 2, 3)$
  Therefore the answer to the original problem is the same as finding the answer to the following problem: find the number of arrays such that each has a length n, with elements sorted in non-decreasing order and in the range $[1, \ M]$. 

  Using this fact we can output the answer for a given pair of $N, M$ as 
 $^{2 \cdot N + M - 1}C_{m - 1}$

  You will need to precompute factorials to answer each test case in $O(1)$

</details>

#### [`CPP_Code`](./../Codes//D_HowManyArrays.cpp)