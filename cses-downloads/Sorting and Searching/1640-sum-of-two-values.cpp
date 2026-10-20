n,k=map(int,input().split())
a=list(map(int,input().split()))
b=sorted(a)
start=0 
end=n-1
flag=1
while(start<=end):
    if(b[start]+b[end]<k):
        start+=1 
    elif(b[start]+b[end]>k):
        end-=1
    else:
        flag=0
        break 
if(flag!=0):
    print("IMPOSSIBLE")
else:
    end_index=n-a[::-1].index(b[end])
    start_index=a.index(b[start])+1
    if(end_index==start_index):
        print("IMPOSSIBLE")
    else:
        print(start_index,end_index)