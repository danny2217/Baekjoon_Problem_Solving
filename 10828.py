import sys

# 1. 입력 속도 빠르게 하기
input = sys.stdin.readline

n = int(input())
stack = []

for _ in range(n):
    # 입력받은 줄을 공백 기준으로 나눕니다.
    command = input().split()
    
    # 1. push: 값 넣기 (리스트의 맨 뒤에 추가)
    if command[0] == "push":
        stack.append(command[1])
        
    # 2. pop: 맨 뒤에 있는 것(가장 최근 것) 꺼내기
    elif command[0] == "pop":
        if stack:
            print(stack.pop()) # popleft()가 아니라 그냥 pop()입니다!
        else:
            print(-1)
            
    # 3. size: 크기 확인
    elif command[0] == "size":
        print(len(stack))
        
    # 4. empty: 비어있는지 확인
    elif command[0] == "empty":
        if stack:
            print(0)
        else:
            print(1)
            
    # 5. top: 맨 위에 있는 것(가장 최근 것) 확인 (꺼내진 않음)
    elif command[0] == "top":
        if stack:
            print(stack[-1]) # 맨 뒤의 값은 인덱스 -1 입니다.
        else:
            print(-1)