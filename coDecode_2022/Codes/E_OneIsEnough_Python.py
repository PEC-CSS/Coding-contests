def get(a, m):
    c = {}
    c[0] = a

    mod = len(a)

    def make(to_use, to_make):
        if to_make in c: return

        if to_use in c:
            c[to_make] = [c[to_use][(j - (1 << i)) % mod] ^ c[to_use][(j + (1 << i)) % mod] for j in range(len(a))]

    to_use = 0
    for i in range(30):
        if (m >> i) & 1:
            make(to_use, to_use + (1 << i))
            to_use += 1 << i;

    return c[m]

for _ in range(int(input())):
    n, m = [int(x) for x in input().split()]

    s = [int(x) for x in input().split()]
    s = [1 if x > 0 else 0 for x in s]

    print(sum(get(s, m)))