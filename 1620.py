import sys
input = sys.stdin.readline

n, m = map(int, input().split())

# 양쪽으로 다 저장해야 함 (이름->번호, 번호->이름)
name_to_id = {}
id_to_name = {}

for i in range(1, n + 1):
    name = input().strip()
    name_to_id[name] = i
    id_to_name[i] = name

for _ in range(m):
    query = input().strip()
    # 입력이 숫자인지 확인
    if query.isdigit():
        print(id_to_name[int(query)])
    else:
        print(name_to_id[query])