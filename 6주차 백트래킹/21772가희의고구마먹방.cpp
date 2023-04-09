/*

 백준 15486  문제
 퇴사 2
*/

#include <algorithm>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;
int R;
int C;
int T;
char map[101][101];
char visit[101][101];
char eat[101][101];
int dogR;
int dogC;
int result = 0;
//상하좌우
int dR[5] = {1, 0, -1, 0, 0};
int dC[5] = {0, 1, 0, -1, 0};

void dfs(int r, int c, int depth, int eatCount) {

    if (depth == T) {
        result = max(result, eatCount);

        return;
        // 정답 출력
    }

    for (int i = 0; i < 4; i++) {
        int newR = r + dR[i];
        int newC = c + dC[i];

        // 맵 범위를 벗어나면

        if (newR < 1 || newR > R || newC < 1 || newC > C) {
            continue;
        }
        // 장애물을 만나면

        if (map[newR][newC] == '#') {
            continue;
        }

        if (map[newR][newC] == 'S') {
            map[newR][newC] = '.';
            dfs(newR, newC, depth + 1, eatCount + 1);
            map[newR][newC] = 'S';

        } else {
            dfs(newR, newC, depth + 1, eatCount);
        }

    }
}

int main(int argc, char *argv[]) {

    // input
    scanf("%d %d %d", &R, &C, &T);

    for (int i = 1; i <= R; i++) {
        for (int k = 1; k <= C; k++) {
            scanf("\n%c", &map[i][k]);
            if (map[i][k] == 'G') {
                map[i][k] = '.';
                dogR = i;
                dogC = k;
            }
        }
    }

    dfs(dogR, dogC, 0, 0);

    printf("%d", result);
}