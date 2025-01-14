def solve():
    n = input().strip() 
    p = int(input())  
    ans = 0
    for char in n:
        ans = ans * 10 + int(char)
        ans %= p
    print(ans)

def main():
    t = 1  
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
