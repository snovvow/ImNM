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

int map[2001][2001];
// 오른쪽으로 향하는놈  , 밑으로 가는 놈
int dR[2] = {0, 1};
int dC[2] = {1, 0};

struct dot {
    int r;
    int c;
    //생성자
    dot() {}
    dot(int _r, int _c) {
        r = _r;
        c = _c;
    }

    bool operator<(const dot &b) const {
        if (r == b.r)
            return c > b.c;
        else
            return r < b.r;
    }
};

priority_queue<dot> pq;

// way 0 오른쪽
// way 1 아래쪽
bool dfs(int r, int c, int depth, int way, int kind) {
    // cout << r << " " << c << endl;

    if (depth == K) {
        cout << "success" << r << " " << c << endl;

        if (map[r][c] == 2) {
            pq.push(dot(r, c));
        }
        map[r][c] = kind;
        return true;
        // 정답 출력
    }

    int newR = r + dR[way];
    int newC = c + dC[way];
    // cout << "new" << newR << " " << newC << endl;

    // 맵 범위를 벗어나면

    if (newR < 1 || newR > N || newC < 1 || newC > M) {
        return false;
    }
    // 장애물을 만나면

    if (map[newR][newC] == 0) {
        return false;
    }

    bool test = dfs(newR, newC, depth + 1, way, kind);

    if (test) {
        if (map[r][c] == 2) {
            pq.push(dot(r, c));
        }
        map[r][c] = kind;
        return true;
    } else {
        return false;
    }
}

void printTest() {
    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= M; k++) {
            cout << map[i][k] << " ";
        }
        cout << endl;
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
    if ()

        for (int i = 1; i <= N; i++) {
            for (int k = 1; k <= M; k++) {
                if (map[i][k] == 1 || map[i][k] == 2) {
                    bool test;
                    test = dfs(i, k, 1, 1, 2);
                    test = dfs(i, k, 1, 0, 2);

                    if (test) {
                        printTest();
                    }
                    test = dfs(i, k, 1, 0, 3);
                    test = dfs(i, k, 1, 1, 3);
                }
            }
        }

    printTest();

    int loop = pq.size();
    cout << loop << endl;
    for (int i = 0; i < loop; i++) {
        dot print = pq.top();
        pq.pop();
        cout << print.r << " " << print.c << endl;
    }
}
