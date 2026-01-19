import sys

input = sys.stdin.readline

n = int(input())
a = set(map(int,input().split()))

m = int(input())
targets = list(map(int, input().split()))

for i in targets:
    if i in a:
        print(1)
    else:
        print(0)