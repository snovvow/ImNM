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
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int R, C;

char v[51][51][2] = {
    0,
};
bool ch[51][51] = {
    false,
};
int cnt = 1;

struct DotchInfo {
    int R;
    int C;
    int turn;
    //생성자
    DotchInfo(int _R, int _C, int _turn) {
        R = _R;
        C = _C;
        turn = _turn;
    }
};

queue<DotchInfo> q;

void flood() {
    for (int i = 1; i <= R; i++) {
        for (int k = 1; k <= C; k++) {
            if (v[i][k][0] == '*') {
                for (int j = 0; j < 4; j++) {
                    int newX = i + dx[j];
                    int newY = k + dy[j];
                    if (newX < 1 || newY < 1 || newX > R || newY > C) {
                        continue;
                    }
                    // 물 불어나기
                    if (v[newX][newY][0] == '.') {
                        v[newX][newY][1] = '*';
                    }
                }
            }
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int k = 1; k <= C; k++) {
            // printf("%c", v[i][k][1]);
            v[i][k][0] = v[i][k][1];
        }
        // printf("\n");
    }
}

bool BFS(DotchInfo dotchInfo) {
    q.push(dotchInfo);
    ch[dotchInfo.R][dotchInfo.C] = true;

    while (!q.empty()) {
        DotchInfo popedDotch = q.front();
        q.pop();

        if (cnt < popedDotch.turn) {
            flood();
            cnt++;
        }
        // printf("(%d , %d , %d )\n", popedDotch.R, popedDotch.C,
        //        popedDotch.turn);

        for (int i = 0; i < 4; i++) {
            int newX = popedDotch.R + dx[i];
            int newY = popedDotch.C + dy[i];
            if (newX < 1 || newY < 1 || newX > R || newY > C) {
                continue;
            }

            if (v[newX][newY][0] == 'D') {
                return true;
            }

            if (v[newX][newY][0] == '.' && ch[newX][newY] == false) {
                //  메모리 초과 해결한 부분. 넘어가기전에 투루로 놔야함 3,3이
                //  안겹치게...
                ch[newX][newY] = true;

                q.push(DotchInfo(newX, newY, popedDotch.turn + 1));
            }
        }
    }
    return false;

    // 다음 빙산으로 넘어가기
}

int main(int argc, char *argv[]) {
    // input

    scanf("%d %d", &R, &C);
    DotchInfo firstDotch(0, 0, 1);
    for (int i = 1; i <= R; i++) {
        for (int k = 1; k <= C; k++) {
            scanf("\n%c", &v[i][k][0]);
            // printf("%c", v[i][k][0]);
            if (v[i][k][0] == 'S') {
                v[i][k][0] = '.';
                firstDotch.R = i;
                firstDotch.C = k;
            }
            v[i][k][1] = v[i][k][0];
        }
    }

    flood();

    if (BFS(firstDotch)) {
        printf("%d", cnt);
    } else {
        printf("KAKTUS");
    }
}