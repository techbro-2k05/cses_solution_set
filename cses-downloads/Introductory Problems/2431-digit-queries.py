def find_kth_digit(k):
    # Initialize variables
    length = 1  # Current length of the numbers (1-digit, 2-digit, etc.)
    count = 9   # Count of numbers of current length
    start = 1   # Starting number of current length (1, 10, 100, etc.)
    
    # Find the range in which the kth digit lies
    while k > length * count:
        k -= length * count
        length += 1
        count *= 10
        start *= 10
    
    # Find the actual number and the exact digit within the number
    number = start + (k - 1) // length  # Find the number containing the kth digit
    digit_index = (k - 1) % length      # Find the specific digit in the number
    
    # Convert number to string to easily get the digit
    return int(str(number)[digit_index])

# Example usage:
q = int(input())  # Number of queries
for _ in range(q):
    k = int(input())  # Query position
    print(find_kth_digit(k))
