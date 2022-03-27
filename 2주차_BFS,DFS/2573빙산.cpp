/*

 백준 2573 문제
 빙산

 dfs 로 한번씩 줄여나가기?
 flag 로 dfs 시작이 두번이상이면... 직전 dfs 호출 하고
 while(1)설정...?
 빙산 녹이기 or dfs 시작이 안된다면 분리되지 않는거임.

*/

/*

 백준 2606 문제
 바이러스
*/

#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int n, m;

int v[301][301][2] = {
    0,
};
bool ch[301][301] = {
    false,
};
int cnt = 0;

void DFS(int x, int y) {
    ch[x][y] = true;

    // 다음 빙산으로 넘어가기
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX < 1 || newY < 1 || newX > n || newY > m) {
            continue;
        }

        if (v[newX][newY][0] > 0 && ch[newX][newY] == false) {

            DFS(newX, newY);
        }
    }
}

int main(int argc, char *argv[]) {
    // input

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= m; k++) {
            scanf("%d", &v[i][k][0]);
            v[i][k][1] = v[i][k][0];
        }
    }

    // dfs
    while (1) {
        bool flag = false;

        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= m; k++) {
                // 빙산 녹이기

                if (v[i][k][0] > 0) {
                    // printf("마이너스 %d %d\n", i, k);

                    for (int j = 0; j < 4; j++) {
                        int newX = i + dx[j];
                        int newY = k + dy[j];
                        if (newX < 1 || newY < 1 || newX > n || newY > m) {
                            continue;
                        }
                        // else 빙산 녹이기

                        if (v[newX][newY][0] <= 0) {
                            v[i][k][1] -= 1;
                        }
                    }
                }
            }
        }
        // 1년 지남
        cnt++;

        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= m; k++) {
                v[i][k][0] = v[i][k][1];
                // printf("%d ", v[i][k][0]);
            }
            // printf("\n");
        }

        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= m; k++) {

                if (v[i][k][0] > 0 && ch[i][k] == false) {
                    // 음수가 될 수 도 있음
                    // printf("%d %d\n", i, k);

                    // 1년 지난거임
                    if (flag) {
                        printf("%d", cnt);
                        return 0;
                    }
                    flag = true;

                    // 0 아니면 dfs 돌리기 시작

                    DFS(i, k);
                }
            }
        }

        // check 배열 초기화
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= m; k++) {
                ch[i][k] = false;
            }
        }
        if (!flag) {
            printf("0");

            return 0;
        }
    }

    // output
    printf("%d", cnt);
}