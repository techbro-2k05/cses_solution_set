def main():
    my_str=input()
    n=len(my_str)
    if(n==1):
        print(my_str)
        return
    my_dict={}
    for i in my_str:
        if(i not in my_dict.keys()):
            my_dict[i]=1
        else:
            my_dict[i]+=1
    ll=list(my_dict.keys())
    odd_count=0
    mid_let=None
    for i in ll:
        if(my_dict[i]&1==1):
            odd_count+=1
            mid_let=i
    if(odd_count>1):
        print("NO SOLUTION")
        return
    for i in ll:
        if(my_dict[i]%2==0):
            print(i*((my_dict[i])//2),end="")
    if(mid_let!=None):
        print(mid_let*(my_dict[mid_let]),end="")
    ll.reverse()
    for i in ll:
        if(my_dict[i]%2==0):
            print(i*((my_dict[i])//2),end="")
    print("")

main()


