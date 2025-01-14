def solve():
    r = int(input())  
    d = int(input())  
    circle = 6 * r  
    d %= circle
    print(min(d, circle - d))

t = 1
# t = int(input())
for _ in range(t):
    solve()
