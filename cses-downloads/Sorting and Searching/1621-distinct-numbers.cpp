import sys

n = int(sys.stdin.readline().strip())  # Fast input for n
my_str = sys.stdin.readline().strip().split()  # Fast input for the list of numbers

# Converting input to integers and finding the number of unique elements
unique_elements = len(set(my_str))

print(unique_elements)
