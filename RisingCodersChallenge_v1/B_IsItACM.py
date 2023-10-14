t = int(input())
for testcase in range(t):
    s = input()
    A, C, M = 0, 0, 0
    for i in range(len(s)):
        if s[i] == 'A':
            A += 1
        if s[i] == 'C':
            C += 1
        if s[i] == 'M':
            M += 1

    if A == 1 and C == 1 and M == 1:
        print("ACM")
    else:
        print("NOPE")

    if 'A' in s and 'C' in s and 'M' in s:
        print("ACM")
    else:
        print("NOPE")