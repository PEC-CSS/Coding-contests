n = int(input())

vec = [['*' for _ in range(2 * n)] for _ in range(2 * n)]

i = 1
while i < n:
    rs, cs = i, i
    re, ce = 2 * n - i, 2 * n - i
    row_start, col_start = rs, cs

    while rs != re:
        vec[rs][cs] = '#'
        vec[rs][ce - 1] = '#'
        rs += 1

    rs = row_start
    while cs != ce:
        vec[rs][cs] = '#'
        vec[re - 1][cs] = '#'
        cs += 1

    i += 2

for row in vec:
    print("".join(row))
