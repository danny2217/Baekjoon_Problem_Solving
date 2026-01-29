import sys

input = sys.stdin.readline

n = int(input())
points = []

for i in range(n):
    
    x,y = map(int, input( ).split())
    points.append((x,y))
    
points.sort

for x,y in points:
    print(x,y)