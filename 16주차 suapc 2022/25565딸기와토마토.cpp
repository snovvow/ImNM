//임의의 연속한 k개의 칸에... 딸기 토마토를 심는다!
// 순차적으로 포문 돌리면서 1인 숫자 발견하면 dfs 돌리기
// ( dfs 돌릴 조건은 1이 아닌경우..? )
// dfs 돌릴때 두방향으로 돌려야함
// 오른쪽으로 가는 방향 , 아래로 내려가는 방향
// 오른쪽 , 아랫쪽이든 방문한놈은 2로바꿈

// 백트레킹으로 K의 조건을 만족하고 , 0 이 아닌 수라면 돌아가면서
// 2같은 수로 바꿈 그자리가 만약 2였다면
// 좌표 우선순위 큐로 넣어서 삽입!

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, M, K, seedCnt;

int map[2002][2002];
// 오른쪽으로 향하는놈  , 밑으로 가는 놈
int dR[4] = {0, 1, 0, -1};
int dC[4] = {1, 0, -1, 0};

bool ifCross(int r, int c) {
    // cout << "in"
    //      << "(" << r << " " << c << ")" << endl;

    for (int i = 0; i < 4; i++) {
        int r1 = r + dR[i % 4];
        int c1 = c + dC[i % 4];
        int r2 = r + dR[(i + 1) % 4];
        int c2 = c + dC[(i + 1) % 4];
        // cout << "next" << i << endl;

        // cout << "(" << r1 << " " << c1 << ")" << endl;
        // cout << "(" << r2 << " " << c2 << ")" << endl;
        if (map[r1][c1] && map[r2][c2]) {
            // cout << "("
            //      << "true"
            //      << ")" << endl;

            return true;
        }
    }
    return false;
}

bool checkRC(int r, int c) {
    int r1 = r + dR[0];
    int c1 = c + dC[0];
    if (map[r1][c1]) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    int input;

    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= M; k++) {
            cin >> input;
            map[i][k] = input;
            if (input)
                seedCnt++;
        }
    }

    if (seedCnt == 2 * K) {
        cout << 0;
        return 0;
    }

    if (K == 1) {
        cout << 1 << endl;

        for (int i = 1; i <= N; i++) {
            for (int k = 1; k <= M; k++) {
                if (map[i][k])
                    cout << i << " " << k << endl;
            }
        }
        return 0;
    }
    // cout << 2 * k - seedCnt;
    // 하나만 겹치는경우
    if (2 * K - 1 == seedCnt) {
        // cout << "seedCnt " << endl;
        for (int i = 1; i <= N; i++) {
            for (int k = 1; k <= M; k++) {
                if (map[i][k] && ifCross(i, k)) {
                    cout << 1 << endl;

                    cout << i << " " << k << endl;
                    return 0;
                }
            }
        }
    }

    // 가로가로 세로세로
    int toMove = 2 * K - seedCnt;
    cout << toMove << endl;
    // cout << "adsfdszfs" << endl;
    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= M; k++) {
            if (map[i][k]) {

                if (checkRC(i, k)) {
                    for (int n = 0; n < toMove; n++) {
                        cout << i << " " << k + K - toMove + n << endl;
                    }
                    //가로
                } else {
                    //세로
                    for (int n = 0; n < toMove; n++) {
                        cout << i + K - toMove + n << " " << k << endl;
                    }
                }
                return 0;
            }
        }
    }
}
