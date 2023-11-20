# <center><u>[B. Super Donuts and Nikhilesh](https://www.hackerrank.com/contests/algorithmic-grand-prix-pecfest2023/challenges/super-donuts-and-nikhilesh)</u></center>
---

We have two constraints here:
1. Eat donuts which are at height less than or equal to $E$ where $E$ is the current energy of Nikhilesh.
2. At each step you eat that donut which maximises your energy.
   
To maximize our energy at each step, we'll eat the donut with the maximum energy count, ensuring it's kept at a height less than or equal to our current energy. To do this, we first sort the donuts based on their heights and add the ones kept at a height less than or equal to our current energy into a `priority queue`. 

Now, we'll pick up the donut with the max energy count that is present in the `priority queue` **and eat it** (it has to be removed from `priority queue` too). After eating, our energy increases, so we need to check if we can eat any more donuts other than the ones already pushed into the `priority queue`.

We repeat this until our `priority queue` becomes empty. 