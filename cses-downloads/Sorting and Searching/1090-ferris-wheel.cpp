def find_maximum_applicants(n, x,a):
    # Sort the desired apartment sizes and the actual apartment sizes
    a.sort()

    i, j = 0, n-1
    matches = 0
    
    # Use two pointers to find the maximum number of applicants that can get an apartment
    if(a[i]>=x):
        return n
    while i <=j:
        if(i==j):
            matches+=1 
            break 
        if a[i]+a[j]>x:
            matches+=1
            # Apartment is too small, move to the next apartment
            j -=1
        elif a[i]+a[j]<=x:
            # Apartment is too large, move to the next applicant
            matches+=1
            j-=1
            i += 1
    return matches

# Example usage:
n, x = map(int, input().split())
child_weight = list(map(int, input().split()))

result = find_maximum_applicants(n, x,child_weight)
print(result)
