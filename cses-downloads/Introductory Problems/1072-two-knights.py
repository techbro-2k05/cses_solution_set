def count_non_attacking_knights(n):
    for k in range(1, n + 1):
        # Total number of ways to place two knights on a k x k chessboard
        total_ways = (k * k) * (k * k - 1) // 2
        
        # Number of ways two knights can attack each other
        if k > 2:
            attacking_pairs = 4 * (k - 1) * (k - 2)
        else:
            attacking_pairs = 0
        
        # Non-attacking ways
        non_attacking_ways = total_ways - attacking_pairs
        print(non_attacking_ways)

# Example usage:
t=int(input())
count_non_attacking_knights(t)
