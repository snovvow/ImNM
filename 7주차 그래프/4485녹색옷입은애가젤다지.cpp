

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
int N;
int distanceSave[15626];
int length[125][125];
int dR[2] = {-1, 0};
int dC[2] = {0, -1};

struct node {
    int end;
    int length;

    // node
    node() {}
    node(int _end, int _length) {
        end = _end;
        length = _length;
    }
    // 비교 구문이 반대로 감? 오름
    bool operator<(const node &b) const { return length > b.length; }
};
// 125 * 125
vector<node> v[15626];

void makeGraph(int r, int c) {
    if (r == N) {
        //종료 조건
        return;
    }
    int startNodeNum = r * N + c;
    for (int i = 0; i < 2; i++) {
        int newR = r + dR[i];
        int newC = c + dC[i];

        // 아래 오른쪽 방향으로 이동중 범위 벗어나면 아웃.
        if (newR < 0 || newC < 0) {
            continue;
        }
        // 노드의 숫자를 계산
        int endNodeNum = newR * N + newC;
        v[startNodeNum].push_back(node(endNodeNum, length[newR][newC]));
        v[endNodeNum].push_back(node(startNodeNum, length[r][c]));
    }

    int newPassC = (c + 1) == N ? 0 : c + 1;
    int newPassR = newPassC == 0 ? r + 1 : r;
    makeGraph(newPassR, newPassC);
}

int dijkstra(int start, int destination) {
    node tmp;

    int result = 0;
    // 1을 기준으로한 거리 초기화
    for (int i = 0; i <= N * N - 1; i++) {
        distanceSave[i] = 9999999;
    }

    distanceSave[start] = length[0][0];
    priority_queue<node> pq;
    tmp.end = start;
    tmp.length = length[0][0];
    pq.push(tmp);

    while (!pq.empty()) {
        // 우선순위 큐에 들어간 정보를 가져온다 ( distanceSave 즉 1번 노드로부터
        // 2,3,...V 번 노드까지의 가장 짧은 거리와 관련.)

        tmp = pq.top();
        // 조사해야할 노드의 id를 가져온다
        int currentIdx = tmp.end;
        // printf("chekc %d", currentIdx);
        // 조사해야할 노드의 최신 거리 정보를 가져온다.
        int currentLength = tmp.length;
        if (currentIdx == destination) {
            result = currentLength;
            break;
        }
        pq.pop();
        for (int i = 0; i < v[currentIdx].size(); i++) {
            // 조사해야하는 노드의 인접노드들을 조사한다.
            int next = v[currentIdx][i].end;

            // 조사해야하는 노드에서 인접노드의 거리정보를 가져온다.
            int nextDistance = v[currentIdx][i].length;
            // printf("%d %d\n", next, nextDistance);

            int startToNextNodeDistance = currentLength + nextDistance;
            if (distanceSave[next] > startToNextNodeDistance) {
                // printf("visit%d %d %d\n", currentIdx, next, nextDistance);

                distanceSave[next] = startToNextNodeDistance;
                pq.push(node(next, startToNextNodeDistance));
            }
        }
    }
    return result;
}

//  (2 ≤ N ≤ 125) N = 0

// 5
// 3 7 2 0 1
// 2 8 0 9 1
// 1 2 1 8 1
// 9 8 9 2 0
// 3 6 5 1 5
// make to list node?

int main(int argc, char *argv[]) {

    // input

    int problemCount = 0;

    scanf("%d", &N);

    while (N != 0) {
        for (int i = 0; i <= N * N - 1; i++) {
            v[i].clear();
        }
        problemCount++;
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < N; k++) {
                // 평탄화 하는작업 end
                // 시작지점을 구해야하는데...
                scanf("%d", &length[i][k]);
            }
        }
        // distanceSave[0][0] = v[0][0];
        makeGraph(0, 1);
        int result = dijkstra(0, N * N - 1);

        // for (int i = 0; i < N * N; i++) {
        //     printf("%d :", i);

        //     for (int k = 0; k < v[i].size(); k++) {
        //         printf("(%d %d)", v[i][k].end, v[i][k].length);
        //     }
        //     printf("\n");
        // }

        // for (int i = 0; i < N * N; i++) {

        //     printf("%d ", distanceSave[i]);
        //     if ((i + 1) % N == 0)
        //         printf("\n", distanceSave[i]);
        // }

        // for (int i = 0; i < N; i++) {
        //     for (int k = 0; k < N; k++) {
        //         // 평탄화 하는작업 end
        //         // 시작지점을 구해야하는데...
        //         printf("%d ", distanceSave[i][k]);
        //     }
        //     printf("\n");
        // }
        printf("Problem %d: %d\n", problemCount, result);

        scanf("%d", &N);
    }
}

// 기존 dp 소스 ( 위로가는 방식때문에 틀림 )
// void dp(int r, int c) {

//     if (r == N) {
//         return;
//     }
//     int saveSmall = 99999999;
//     // 빼기임!
//     int fromR;
//     int fromC;
//     for (int i = 0; i < 2; i++) {
//         int newR = r + dR[i];
//         int newC = c + dC[i];

//         // 아래 오른쪽 방향으로 이동중 범위 벗어나면 아웃.
//         if (newR < 0 || newC < 0) {
//             continue;
//         }

//         if (saveSmall > distanceSave[newR][newC]) {
//             fromR = newR;
//             fromC = newC;
//             saveSmall = distanceSave[newR][newC];
//         }
//     }

//     distanceSave[r][c] = v[r][c] + saveSmall;
//     printf("(%d %d) = (%d %d) + %d\n", r, c, fromR, fromC, saveSmall);

//     int newPassC = (c + 1) == N ? 0 : c + 1;
//     int newPassR = newPassC == 0 ? r + 1 : r;
//     dp(newPassR, newPassC);
// }