t=int(input())
while t:
    n=int(input())
    s=input()
    count={}
    for i in range(len(s)):
        if s[i] in count:
            count[s[i]]+=1
        else:
            count[s[i]]=1
    ans=len(count)
    temp={}
    for i in range(len(s)):
        if s[i] in temp:
            temp[s[i]]+=1
        else:
            temp[s[i]]=1
        count[s[i]]-=1
        if(count[s[i]]==0):
            del count[s[i]]
        curr=len(count)+len(temp)
        ans=max(ans, curr)
    print(ans)
    t-=1