import sys
import heapq # 힙(우선순위 큐) 모듈

input = sys.stdin.readline
n = int(input())
heap = []

for _ in range(n):
    x = int(input())
    
    if x == 0:
        if not heap: # 비어있으면 0 출력
            print(0)
        else:
            # 가장 작은 값을 꺼내서 출력 (자동 정렬됨)
            print(heapq.heappop(heap))
    else:
        # 값을 힙에 넣음
        heapq.heappush(heap, x)