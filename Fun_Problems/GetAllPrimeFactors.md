# [3. Get All Prime Factors](https://www.hackerrank.com/contests/testing-1669399991/challenges/prime-factors-9-4)

You can find prime factor of each $N$ in $O(\sqrt N)$ time. But the overall complexity will be $O(T \cdot \sqrt N)$ where $T$ is number of testcase.

- $T_{max} = 10^6$
- $N_{max} = 10^7$

So you will be doing approximately $10^6 \cdot 10^{3.5} = 10^{9.5}$ operations which will not fit within time limit.

### Idea

There cannot be more than $log_2(n)$ prime factors of any number. 

For clarity purpose, $4 (= 2^2)$ has $2$ prime factors, **NOT** $1$.

If for each number from $2$ to $N$ we can get a prime number that divides it efficiently then we can do something like:

```cpp
while (N > 1) {
    int p = getPrimeDivisorOfN(N);
    freq[p] += 1; // freq stores frequency of prime factors
    N /= p;
}
```

How to write `getPrimeDivisorOfN()` function?

You can read [this tutorial](https://cp-algorithms.com/algebra/prime-sieve-linear.html) for details. Once you understand this, you are done.