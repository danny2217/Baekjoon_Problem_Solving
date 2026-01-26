#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // INT_MAX 사용을 위해 필요
#include <math.h>

// 좌표를 저장할 구조체
typedef struct {
    int r;
    int c;
} Point;

int N, M;
int map[51][51];

// 집과 치킨집 좌표만 따로 저장 (최대 개수 고려)
Point houses[100];      // 집의 개수는 2N을 넘지 않음 (N=50일 때 100)
Point chickens[13];     // 치킨집은 최대 13개
int house_cnt = 0;
int chicken_cnt = 0;

// 선택된 치킨집을 표시할 배열 (방문 체크)
int selected[13]; 
int min_city_dist = INT_MAX; // 최소 도시 치킨 거리 (정답)

// 거리 계산 함수 (절대값 합)
int get_dist(Point a, Point b) {
    return abs(a.r - b.r) + abs(a.c - b.c);
}

// DFS: 치킨집 M개를 뽑는 조합 함수
// idx: 현재 탐색 중인 치킨집 인덱스
// count: 현재까지 선택한 치킨집 개수
void dfs(int idx, int count) {
    // 1. M개를 다 뽑았으면 거리 계산 시작
    if (count == M) {
        int current_city_dist = 0;

        // 모든 집에 대해
        for (int i = 0; i < house_cnt; i++) {
            int min_dist = INT_MAX; // 해당 집에서 가장 가까운 치킨집 거리
            
            // 선택된 치킨집들과의 거리 비교
            for (int j = 0; j < chicken_cnt; j++) {
                if (selected[j]) { // 선택된 치킨집만 계산
                    int d = get_dist(houses[i], chickens[j]);
                    if (d < min_dist) min_dist = d;
                }
            }
            current_city_dist += min_dist; // 도시 치킨 거리에 누적
        }

        // 최소값 갱신
        if (current_city_dist < min_city_dist) {
            min_city_dist = current_city_dist;
        }
        return;
    }

    // 2. 백트래킹으로 치킨집 선택 (조합)
    for (int i = idx; i < chicken_cnt; i++) {
        if (!selected[i]) {
            selected[i] = 1;        // 선택 함
            dfs(i + 1, count + 1);  // 다음 단계로
            selected[i] = 0;        // 선택 취소 (백트래킹)
        }
    }
}

int main() {
    // 입력 받기
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int temp;
            scanf("%d", &temp);
            
            // 1이면 집 리스트에 추가
            if (temp == 1) {
                houses[house_cnt].r = i;
                houses[house_cnt].c = j;
                house_cnt++;
            }
            // 2면 치킨집 리스트에 추가
            else if (temp == 2) {
                chickens[chicken_cnt].r = i;
                chickens[chicken_cnt].c = j;
                chicken_cnt++;
            }
        }
    }

    // DFS 시작 (0번 인덱스부터, 0개 선택 상태)
    dfs(0, 0);

    // 정답 출력
    printf("%d\n", min_city_dist);

    return 0;
}