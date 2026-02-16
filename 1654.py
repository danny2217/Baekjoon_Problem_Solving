import sys

input = sys.stdin.readline
K, N = map(int, input().rstrip().split())
lines = [int(input()) for _ in range(K)]

start = 1 # 0으로 나누면 ZeroDivisionError 나니까 1부터!
end = max(lines) 

result = 0

while start <= end:
    mid = (start + end) // 2
    
    # 1. mid 길이로 잘랐을 때 총 몇 개 나오는지 계산 (Hint 2 참고)
    total_count = 0
    for i in lines:
        total_count += i // mid
    # 2. 개수에 따라 start, end 조절 (Hint 3 참고)
    if total_count >= N:
        result = mid
        start = mid + 1
    else:
       end = mid - 1
        
print(result) 