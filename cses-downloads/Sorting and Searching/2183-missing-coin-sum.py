def find_min_sum_not_formable(arr):
    arr.sort()
    min_unreachable = 1
    
    for num in arr:
        if num > min_unreachable:
            break
        min_unreachable += num
    
    return min_unreachable

# Example usage
n=int(input())
arr = list(map(int, input().split()))
print(find_min_sum_not_formable(arr))
