# <center><u>[B. Shivalik Hostel Room](https://www.hackerrank.com/contests/algorithmic-grand-prix-pecfest2023/challenges/shivalik-hostel-room)</u></center>
---

Since we need to maximise the total sum of all rooms, we will increase the size of smallest room to maximum size possible. 

Let us sort the queries $(C_j, S_j)$ in decreasing order of $S_j$. $C_j$ and $S_j$ has same meaning as mentioned in problem statement. Now, once we change the room size of any room we will no longer consider it for increments. To maximise total size, we will start by changing the room with minimum size. To ensure that we iterate over rooms in increasing order, we should sort it in increasing order as well.

<details>

<summary> Why change size of room only once? </summary>

Since we have sorted queries in decreasing order of $S_j$ so if we change the room size once to $S_j$ then changing it again to $S_{j - 1}, S_{j - 2},\ \cdots\ or S_1$ will not do any good to us, as $S_j > S_k$ for all $k < j$.

</details>

