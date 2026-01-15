import sys

input = sys.stdin.readline
n = int(input())

# 2의 제곱수인 경우 (1, 2, 4, 8 ...) -> 답은 N 그대로
# (n & (n-1)) == 0 은 2의 제곱수인지 판별하는 비트 연산
square = 2
while True:
    if n == 1 or n == 2:
        print(n)
        break
        
    if square >= n:
        # 공식 적용: (N - 직전 2의 제곱수) * 2
        print((n - (square // 2)) * 2)
        break
        
    square *= 2