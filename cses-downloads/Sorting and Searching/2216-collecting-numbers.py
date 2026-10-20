def solve(n,a):
    ans=1
    b=[0]*(n+1)
    for i in range(n):
        b[a[i]]=i 
    for i in range(1,n):
        if(b[i+1]<b[i]):
            ans+=1
    print(ans)

        

n=int(input())
a=list(map(int,input().split()))
solve(n,a)