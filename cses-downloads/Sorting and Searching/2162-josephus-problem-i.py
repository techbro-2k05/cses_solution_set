from collections import deque

def solve(N):
    q = deque(range(1, N+1))
    flag = False

    while q:
        ele = q.popleft()
        if flag:
            print(ele,end=" "),
        else:
            q.append(ele)
        flag = not flag

N = int(input())
solve(N)