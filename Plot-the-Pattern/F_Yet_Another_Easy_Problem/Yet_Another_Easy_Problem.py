n, a, b = map(int, input().split())

cnt = 0
cnt2 = 0
cnt3 = 9

for i in range(2 * n * a):
    tmp1 = i % n
    for j in range(2 * n * b):
        tmp2 = j % n
        if tmp1 == 0 or tmp1 == n - 1:
            print('*', end='')
        elif tmp2 == 0 or tmp2 == n - 1:
            print('*', end='')
        else:
            if cnt == 0:
                if tmp1 + tmp2 == n - 1:
                    if tmp1 == tmp2 == n // 2 and n % 2 == 1:
                        print(cnt2, end='')
                        cnt2 += 1
                        if cnt2 == 10:
                            cnt2 = 0
                    else:
                        print('*', end='')
                else:
                    print(' ', end='')
            else:
                if tmp1 == tmp2:
                    if tmp1 == n // 2 and n % 2 == 1:
                        print(cnt3, end='')
                        cnt3 -= 1
                        if cnt3 == -1:
                            cnt3 = 9
                    else:
                        print('*', end='')
                else:
                    print(' ', end='')

        if tmp2 == n - 1:
            cnt = (cnt + 1) % 2
    if tmp1 == n - 1:
        cnt = (cnt + 1) % 2
    print()
