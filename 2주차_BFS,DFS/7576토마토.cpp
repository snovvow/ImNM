/*

 백준 7576 문제
 토마토
*/

#include <algorithm>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <utility>
#include <vector>
using namespace std;

int v[1001][1001] = {
    0,
};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int m, n;
int res = 0;
queue<pair<pair<int, int>, int>> q;

void BFS() {
    while (!q.empty()) {
        int saveX = q.front().first.first;
        int saveY = q.front().first.second;
        int depth = q.front().second;
        // printf("(%d , %d )\n", saveX, saveY);
        res = max(res, depth);
        q.pop();
        bool flag = false;
        for (int i = 0; i < 4; i++) {
            int newX = saveX + dx[i];
            int newY = saveY + dy[i];
            if (newX < 1 || newY < 1 || newX > n || newY > m) {
                continue;
            }
            if (v[newX][newY] == 0) {
                // printf("next");
                v[newX][newY] = 1;
                // printf("(%d , %d )\n", newX, newY);
                q.push(make_pair(make_pair(newX, newY), depth + 1));
                // BFS(newX, newY, res);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &m, &n);
    // 가로 , 세로임
    // 열 , 행

    // input
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= m; k++) {
            scanf("%d", &v[i][k]);
            if (v[i][k] == 1)
                q.push(make_pair(make_pair(i, k), 0));
        }
    }

    // BFS
    BFS();

    // check 안익은놈이 있는지
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= m; k++) {
            // 익은 놈일 때만 돌리고
            if (v[i][k] == 0) {
                printf("-1");
                return 0;
            }
        }
    }

    // output

    printf("%d", res);
}