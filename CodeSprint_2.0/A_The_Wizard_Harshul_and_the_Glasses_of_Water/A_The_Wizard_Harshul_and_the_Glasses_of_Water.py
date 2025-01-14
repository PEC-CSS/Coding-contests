def solve():
    n = int(input())
    v = list(map(int, input().split()))
    print(sum(v))

t = 1
# t = int(input())
for _ in range(t):
    solve()
