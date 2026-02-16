import sys
from collections import Counter

input = sys.stdin.readline

N = int(input())
N_arr = list(map(int, input().strip().split()))

M = int(input())
M_arr = list(map(int, input().strip().split()))

count_dic = Counter(N_arr)
result = []

for i in M_arr:
    result.append(count_dic[i])

print(*result) 