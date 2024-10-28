def generate(cnt, n):
    result = ""
    
    if 2 * cnt >= n:
        result = "* " * n
    else:
        result += "* " * cnt
        result += "  " * (n - 2 * cnt)
        result += "* " * cnt
    
    return result

n = int(input())
pattern = []

start_value = (n // 2) + 1
for i in range(start_value, 0, -1):
    pattern.append(generate(i, n))

for i in range(2, start_value + 1):
    pattern.append(generate(i, n))

for line in pattern:
    print(line)
