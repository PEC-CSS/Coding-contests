j = input().split()
n = int(j[0])
if len(j) == 1:
    d = int(input())
else:
    d = int(j[1])

a = input().split()
td = 0

for i in range(len(a)):
    a[i] = int(a[i])
    td += a[i]

s = 0
r = d % td
i = 0

while r > s:
    s += a[i]
    i += 1

r = r - s + a[i - 1]

if r > a[i - 1] - r:
    c = i
    r = a[i - 1] - r
else:
    c = i - 1

if c == n:
    c = 0

print(c)
print(r)
