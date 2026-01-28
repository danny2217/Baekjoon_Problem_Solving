#include <stdio.h>

// 북, 동, 남, 서 (문제 정의 순서)
// 북(0): 행-1, 동(1): 열+1, 남(2): 행+1, 서(3): 열-1
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int N, M;
int map[51][51]; // 0: 빈칸, 1: 벽, 2: 청소함
int r, c, d;     // 로봇 위치(row, col), 바라보는 방향(dir)
int cnt = 0;     // 청소한 칸 개수

int main() {
    // 1. 입력 받기
    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &r, &c, &d);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    // 2. 시뮬레이션 시작
    while (1) {
        // [1단계] 현재 칸이 청소되지 않은 경우, 현재 칸을 청소한다.
        if (map[r][c] == 0) {
            map[r][c] = 2; // 2는 '청소 완료'를 의미
            cnt++;
        }

        int cleaned = 0; // 주변 4칸 중 청소할 곳이 있었는지 체크

        // [2단계] 현재 방향 기준 왼쪽부터 4방향 탐색
        for (int i = 0; i < 4; i++) {
            // 왼쪽으로 회전! (북0 -> 서3 -> 남2 -> 동1)
            d = (d + 3) % 4; 
            
            int nr = r + dr[d];
            int nc = c + dc[d];

            // 맵 범위 체크 & 청소하지 않은 빈 칸(0)이 있는지 확인
            if (nr >= 0 && nr < N && nc >= 0 && nc < M && map[nr][nc] == 0) {
                // 전진하고 반복문 탈출 (1번 단계로 돌아감)
                r = nr;
                c = nc;
                cleaned = 1;
                break; 
            }
        }

        // [3단계] 4방향 모두 청소가 되어있거나 벽인 경우
        if (cleaned == 0) {
            // 바라보는 방향 유지한 채로 후진
            int back_r = r - dr[d];
            int back_c = c - dc[d];

            // 뒤쪽이 벽이라 후진할 수 없다면 작동 멈춤
            if (back_r >= 0 && back_r < N && back_c >= 0 && back_c < M) {
                 if (map[back_r][back_c] == 1) {
                     break; // 종료
                 } else {
                     // 벽이 아니면 후진 (방향 d는 그대로)
                     r = back_r;
                     c = back_c;
                 }
            } else {
                break; // 범위 밖이면 종료 (문제 조건상 벽으로 둘러싸여 있어 이럴 일은 거의 없음)
            }
        }
    }

    // 3. 결과 출력
    printf("%d\n", cnt);

    return 0;
}