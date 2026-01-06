import sys

N = int(input( ))
waiting = list(map(int, sys.stdin.readline().split()))

waiting.sort()
ans = 0

for i in range (1,N+1):
    ans += sum(waiting[:i])

print(ans)