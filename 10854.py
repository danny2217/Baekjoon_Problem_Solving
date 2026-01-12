import sys
from collections import deque

# 1. input을 sys.stdin.readline으로 덮어쓰기 (속도 향상 및 편의성)
input = sys.stdin.readline

n = int(input())

queue = deque()

for i in range(n):
    # 3. 입력받은 줄을 공백 기준으로 나눕니다.
    command = input().split()
    
    if command[0] == "push":
        queue.append(command[1])
        
    elif command[0] == "pop":
        if queue:
            print(queue.popleft()) 
        else:
            print(-1)
            
    elif command[0] == "size":
        print(len(queue))
        
    elif command[0] == "empty":
        if queue:
            print(0)
        else:
            print(1)
            
    elif command[0] == "front":
        if queue:
            print(queue[0])
        else:
            print(-1)
            
    elif command[0] == "back":
        if queue:
            print(queue[-1])
        else:
            print(-1)