n = int(input())
if n == 0:
    # No elements to process
    print(0)
    exit()

a = list(map(int, input().split()))

if len(a) != n:
    print("Input length does not match the specified number of elements.")
    exit()

# Calculate frequencies
frequency = {}
for num in a:
    if num in frequency:
        frequency[num] += 1
    else:
        frequency[num] = 1

# Find the most frequent value
max_key = max(frequency, key=frequency.get)

# Calculate the cost to make all values equal to `max_key`
cost_max_key = sum(abs(max_key - x) * frequency[x] for x in frequency if x != max_key)

# Calculate the cost to make all values equal to the median
a.sort()
median = a[n // 2] if n % 2 == 1 else a[n // 2 - 1]
cost_median = sum(abs(median - x) for x in a)

# Print the minimum of the two costs
print(min(cost_max_key, cost_median))
