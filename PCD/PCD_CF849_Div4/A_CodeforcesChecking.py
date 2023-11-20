t=int(input())
while t>0:
    s="codeforces"
    c=input()
    check=False
    for i in range(len(s)):
        if s[i]==c:
            check=True
            print("YES")
            break
    if check==False:
        print("NO")
    t-=1