import sys
input = sys.stdin.readline

n = int(input())
words = []

for i in range(n):
    words.append(input().strip())

# 1. set으로 중복 제거 -> 다시 list로 변환
words = list(set(words))

# 2. 정렬 (길이 우선, 그 다음 단어 자체)
words.sort(key=lambda x: (len(x), x))

for w in words:
    print(w)