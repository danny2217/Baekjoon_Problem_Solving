import sys

number_group = sys.stdin.readline().strip().split('-')
temp = []

for i in number_group:
    min_element = 0
    for j in i.split('+'):
        min_element+=int(j)
    temp.append(min_element)
    
result = temp[0]
for i in temp[1:]:
    result -= i 

print(result)