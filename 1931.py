import sys

N = int(input( ))
Time_Line = [ ]
for i in range(N):
    start, end = map(int, sys.stdin.readline().split())
    Time_Line.append((start, end))
    
Time_Line.sort(key=lambda x : (x[1],x[0]))

count = 1
end = Time_Line[0][1]

for i in range(1,N):
    if Time_Line[i][0] >= end:
        end = Time_Line[i][1]
        count += 1
        
print (count)