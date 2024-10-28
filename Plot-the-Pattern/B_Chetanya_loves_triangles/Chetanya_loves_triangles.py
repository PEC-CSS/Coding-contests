rows = int(input())

for i in range(1, rows + 1):
    for j in range(2 * rows - i, i, -1):
        print(" ", end="")

    for j in range(i, 0, -1):
        if j == i or j == 1:
            print("* ", end="")
        else:
            print("  ", end="")

    print() 

for i in range(rows - 1, 0, -1):
    for j in range(2 * rows - i, i, -1):
        print(" ", end="")

    for j in range(i, 0, -1):
        if j == i or j == 1:
            print("* ", end="")
        else:
            print("  ", end="")

    print()
