t=int(input())
while(t>0):
  n=int(input())
  alist=input().split()
  absum=0
  min1=abs(int(alist[0]))
  count=0
  for i in alist:
    i=int(i)
    if(i<0):
      count=count+1
    absum+=abs(i)
    min1=min(min1,abs(i))
  if(count%2==0):
    print(absum)
  else:
    print(absum-(2*min1))
   
  t=t-1
