from itertools import combinations,permutations
my_str=input()
per=list(permutations((my_str),len(my_str)))
per=list(set(per))
per.sort()
print(len(per))
for i in per:
    print("".join(i))