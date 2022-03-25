/*

 백준 2206 문제
 벽부수고 이동하기
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <tuple>
// #include <utility>
// #include <vector>
using namespace std;

int v[1001][1001][2] = {
    0,
};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int n, m;
int res = 0;
queue<tuple<int, int, int, bool>> q;

void BFS() {
    q.push(make_tuple(1, 1, 1, false));
    while (!q.empty()) {
        int saveX = get<0>(q.front());
        int saveY = get<1>(q.front());
        int depth = get<2>(q.front());
        bool isBreak = get<3>(q.front());

        // printf("(%d , %d ) depth : %d , break : %d \n", saveX, saveY, depth,
        //        isBreak);
        res = max(res, depth);

        if (saveX == n && saveY == m) {
            break;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int newX = saveX + dx[i];
            int newY = saveY + dy[i];
            if (newX < 1 || newY < 1 || newX > n || newY > m) {
                continue;
            }
            // 지나갈수 있는 곳일 때
            if (isBreak) {
                // 이미 깨부신 배열 (1)
                if (v[newX][newY][1] == 0) {
                    v[newX][newY][1] = 1;

                    q.push(make_tuple(newX, newY, depth + 1, isBreak));
                }

            } else {
                // 정상 진행
                if (v[newX][newY][0] == 0) {
                    v[newX][newY][0] = 1;
                    q.push(make_tuple(newX, newY, depth + 1, isBreak));
                }

                //부실때
                if (v[newX][newY][0] == 1) {
                    v[newX][newY][1] = 0;
                    q.push(make_tuple(newX, newY, depth + 1, true));
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &n, &m);
    //행 열임

    // input
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= m; k++) {
            scanf("%1d", &v[i][k][0]);
            v[i][k][1] = v[i][k][0];
        }
    }
    v[1][1][0] = 1;
    v[1][1][1] = 1;
    // BFS 레벨값 구하기?
    BFS();

    // check 안익은놈이 있는지
    if (v[n][m][0] != 1 && v[n][m][1] != 1) {
        printf("-1");

        return 0;
    }

    // output

    printf("%d", res);
}