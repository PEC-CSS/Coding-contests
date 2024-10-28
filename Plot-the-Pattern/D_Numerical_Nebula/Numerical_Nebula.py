n = int(input())

cnt1 = n // 2
cnt2 = n // 2
cnt3 = 1
check = False

print('*' * (n + 2))

for j in range(n):
    print('*', end="")
    for i in range(n):
        if i == cnt1 or i == cnt2:
            print(cnt3, end="")
            cnt3 += 1
            if cnt3 == 10:
                cnt3 = 0
        else:
            print(' ', end="")
    
    if not check:
        cnt1 += 1
        cnt2 -= 1
        if cnt2 == 0:
            check = True
    else:
        cnt1 -= 1
        cnt2 += 1

    print('*')

print('*' * (n + 2))
