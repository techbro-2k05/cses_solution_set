def can_empty_piles(a, b):
    # Check if the sum of coins is divisible by 3
    if (a + b) % 3 != 0:
        return "NO"
    # Check if one pile has more than double the coins of the other
    if a > 2 * b or b > 2 * a:
        return "NO"
    return "YES"

# Read input
t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    print(can_empty_piles(a, b))