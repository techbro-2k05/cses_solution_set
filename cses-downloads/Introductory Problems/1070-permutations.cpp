n=int(input())
if(n==1):
    print("1")
elif(n<4):
    print("NO SOLUTION")
elif(n==4):
    print("2 4 1 3")
else:
    if(n%2==0):
        m=n-1
        for i in range(m,5,-2):
            print(i,end=" ")
        print("4 2 5 3 1",end=" ")
        for i in range(6,n+1,2):
            print(i,end=" ")
        print("")
    else:
        m=n
        for i in range(m,5,-2):
            print(i,end=" ")
        print("4 2 5 3 1",end=" ")
        for i in range(6,n+1,2):
            print(i,end=" ")
        print("")
    