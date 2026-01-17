import sys

input = sys.stdin.readline
t = int(input())

for i in range (t):
    stack = [ ]
    a = input().strip()
    is_vps = True
    
    for ch in a:
        if ch == '(':
            stack.append(ch)
        else:
            if stack:
                stack.pop()
            else:
                is_vps = False
                break
    
    if is_vps and not stack:
        print("YES")
    else:
        print("NO")