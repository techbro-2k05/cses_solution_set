n=int(input())
count=0 
copy=n
i=2
while(copy>=i):
    count+=(copy)//i
    i*=2 
count_5=0
i=5
while(n>=i):
    count_5+=(n)//i
    i*=5
print(min(count,count_5))

    