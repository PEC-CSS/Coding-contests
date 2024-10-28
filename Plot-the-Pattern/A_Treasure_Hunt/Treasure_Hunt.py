n = int(input())
cnt = 1

for i in range(1, n + 1):
    for j in range(i):
        print(cnt, end=" ")
        cnt += 1
    print()

start = cnt - 1
for i in range(n, 0, -1):
    for j in range(i):
        print(start, end=" ")
        start -= 1
    print()
