def mod_exp(a, b, mods):
    result = 1
    base = a % mods
    while b > 0:
        if b % 2 == 1:
            result = (result * base) % mods
        base = (base * base) % mods
        b //= 2
    return result

n = int(input())
mods = 1000000007

for i in range(n):
    a, b = map(int, input().split())
    if b == 0:
        print("1")
    elif a == 0 and b != 0:
        print("0")
    else:
        print(mod_exp(a, b, mods))
