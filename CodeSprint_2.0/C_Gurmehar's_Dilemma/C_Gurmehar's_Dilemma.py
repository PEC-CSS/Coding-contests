def solve():
    n, p, k = map(int, input().split())
    v = list(map(int, input().split()))

    v.sort()
    if p <= 0:
        for i in range(n):
            if k == 0:
                break
            if v[i] <= 0:
                v[i] *= p
                k -= 1
    else:
        for i in range(n - 1, -1, -1):
            if k == 0:
                break
            if v[i] >= 0:
                v[i] *= p
                k -= 1

    print(sum(v))

t = 1
# t = int(input())
for _ in range(t):
    solve()
