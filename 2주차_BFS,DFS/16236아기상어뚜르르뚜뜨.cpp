/*

 백준 16236 문제
 아기상어
*/

#include <algorithm>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;

int v[21][21];
bool ch[21][21] = {
    false,
};

int dy[4] = {
    0,
    -1,
    0,
    1,
};
int dx[4] = {-1, 0, 1, 0};
// 행렬 사이즈
int n;

// 엄마 상어 안부르고
int cnt = 0;
int fishCount = 0;

// 초기 사이즈 2
int babySharkSize = 2;
int eatCnt = 0;
int sharkX, sharkY;

// queue<tuple<int, int, int>> q;
bool flag = false;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        // 위에있는게 같으면
        // 왼쪽에 있느놈 ( 내림 차순 )
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

void BFS(int x, int y) {
    queue<tuple<int, int, int>> q;
    vector<pair<int, int>> list;

    q.push(make_tuple(x, y, 0));

    while (!q.empty()) {
        int saveX = get<0>(q.front());
        int saveY = get<1>(q.front());
        int depth = get<2>(q.front());

        //먹기,break;
        if (v[saveX][saveY] >= 1 && babySharkSize > v[saveX][saveY]) {
            //같은 레벨별 모든걸 조사해야함.
            while (!q.empty()) {
                int getX = get<0>(q.front());
                int getY = get<1>(q.front());
                if (v[getX][getY] >= 1 && babySharkSize > v[getX][getY]) {
                    if (depth != get<2>(q.front())) {
                        //레벨 깊이가 달라진다면 아웃.
                        break;
                    }
                    list.push_back(make_pair(getX, getY));
                }
                // int saveY = ;

                q.pop();
            }

            sort(list.begin(), list.end(), compare);
            // for (int i = 0; i < list.size(); i++) {
            //     printf("same : (%d , %d)\n", list[i].first, list[i].second);
            // }

            // 상어위치 최신화
            sharkX = list[0].first;
            sharkY = list[0].second;

            // 먹었는지 검사ㅏ
            flag = true;
            // 레벨 업
            eatCnt++;
            if (eatCnt == babySharkSize) {
                babySharkSize++;
                eatCnt = 0;
            }

            // 먹으면 먹이없애고
            // printf("sharksize %d\n", babySharkSize);

            v[sharkX][sharkY] = 0;
            fishCount--;
            cnt += depth;
            // printf("eat (%d %d %d %d)\n\n", sharkX, sharkY, depth, cnt);

            // printf("sharksize %f %d\n", babySharkSize, (int)babySharkSize);

            break;
        }
        q.pop();

        for (int j = 0; j < 4; j++) {
            // 맨위 , 왼쪽 이면 큐에 집어넣는 순은  위 , 왼쪽  , ( 오른쪽 ,
            // 아래) 여야 함
            int newX = saveX + dx[j];
            int newY = saveY + dy[j];
            if (newX < 1 || newY < 1 || newX > n || newY > n) {
                continue;
            }
            if ((int)babySharkSize < v[newX][newY]) {
                // 크기가 같은 물고기는 지나감
                // printf("check (%d %d)\n", newX, newY);

                continue;
            }

            if (!ch[newX][newY]) {
                // printf("%d %d (%d) (%d)\n", newX, newY, depth + 1,
                //        v[newX][newY]);

                ch[newX][newY] = true;
                q.push(make_tuple(newX, newY, depth + 1));
            }
        }
    }
}

int main(int argc, char *argv[]) {

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= n; k++) {
            scanf("%d", &v[i][k]);
            if (v[i][k] == 9) {
                // 아기상어의 초기 위치를 파악
                v[i][k] = 0;
                sharkX = i;
                sharkY = k;
            } else if (v[i][k] > 0) {
                fishCount++;
            }
        }
    }

    while (1) {

        // 엄마 상어

        // printf("input (%d %d)\n", sharkX, sharkY);
        flag = false;

        if (fishCount > 0) {
            BFS(sharkX, sharkY);

        } else {
            printf("%d", cnt);
            return 0;
        }
        if (!flag) {
            // 엄마요청
            printf("%d", cnt);
            return 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= n; k++) {
                // printf("%d ", v[i][k]);
                ch[i][k] = false;
            }
            // printf("\n");
        }

        // printf("----------\n\n\n\n");

        //     // bfs 탐색결과 먹을 수 있는 물고기가 없을 때??
    }

    // 1마리 그거
    //  여러마리면 가장 가까운 ( bfs )
    //  가장 가까운놈이 여러마리면 위  ,위도 여러마리면 가장 왼쪽
    // }

    // output
}