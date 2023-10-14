for _ in range(int(input())):
    n, m = [int(x) for x in input().split()]
    alice = [int(x) for x in input().split()]
    bob = [int(x) for x in input().split()]

    score = n - m 
    for i in range(len(alice)):
        score += alice[i]
        score -= bob[i]

    if score > 0:
        print("YES")
    else:
        print("NO")