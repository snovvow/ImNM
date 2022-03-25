/*

 백준 4963 문제
 섬의 개수
 행x 렬y 주의하기
*/

#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

int v[51][51];
// 입력정보
bool ch[51][51] = {
    false,
};
//체크 정보

//세방향 탐색 오른쪽 ,아래 ,대각선오른쪽 아래
int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int w, h;
void DFS(int i, int k) {

    for (int d = 0; d < 8; d++) {
        int x = i + dx[d];
        int y = k + dy[d];
        // printf("allx %d y %d\n", x, y);

        if (x > h || y > w || x < 1 || y < 1) {
            // 영역을 벗어나면
            continue;
        }
        if (v[x][y] == 1 && ch[x][y] == false) {

            ch[x][y] = true;
            DFS(x, y);
        }
    }
}

int main(int argc, char *argv[]) {

    while (1) {
        scanf("%d %d", &w, &h);

        int cnt = 0;

        if (w == 0 && h == 0) {
            break;
        }

        //배열 초기화
        for (int i = 1; i <= 50; i++) {
            for (int k = 1; k <= 50; k++) {
                ch[i][k] = false;
                v[i][k] = 0;
            }
        }
        // h 행 w 열
        for (int i = 1; i <= h; i++) {
            for (int k = 1; k <= w; k++) {
                scanf("%d", &v[i][k]);
            }
        }

        for (int i = 1; i <= h; i++) {
            for (int k = 1; k <= w; k++) {

                if (ch[i][k] == false && v[i][k] == 1) {

                    DFS(i, k);
                    cnt++;
                }
            }
        }

        printf("%d\n", cnt);
    }
}