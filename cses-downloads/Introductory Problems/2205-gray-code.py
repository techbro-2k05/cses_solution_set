def generate_gray_code(n):
    if n == 0:
        return ["0"]
    if n == 1:
        return ["0", "1"]
    
    # Recursively get the gray code for n-1
    previous_gray_code = generate_gray_code(n - 1)
    
    # Initialize new Gray code list
    gray_code = []
    
    # Prefix '0' to the previous Gray code
    for code in previous_gray_code:
        gray_code.append("0" + code)
    
    # Prefix '1' to the reversed previous Gray code
    for code in reversed(previous_gray_code):
        gray_code.append("1" + code)
    
    return gray_code

# Example usage:
n=int(input()) # Number of bits
gray_codes = generate_gray_code(n)
print("\n".join(gray_codes))
