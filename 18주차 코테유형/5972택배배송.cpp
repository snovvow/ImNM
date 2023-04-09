#include <algorithm>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;
int N;
int M;
int distanceSave[50001];

struct node {
    int start;
    int end;
    int length;
    node() {}
    node(int _end, int _length) {
        end = _end;
        length = _length;
    }
    node(int _start, int _end, int _length) {
        start = _start;
        end = _end;
        length = _length;
    }
    bool operator<(const node &b) const { return length > b.length; }
};

vector<node> v[50001];
int answer[50001];
priority_queue<node> pq;

int dijkstra(int start, int destination) {
    node tmp;
    int currentIdx, currentLength, next, nextDistance;

    distanceSave[start] = 0;
    pq.push(node(start, 0));

    while (!pq.empty()) {
        tmp = pq.top();
        // 조사해야할 노드의 id를 가져온다
        currentIdx = tmp.end;
        currentLength = tmp.length;
        pq.pop();
        for (int i = 0; i < v[currentIdx].size(); i++) {
            // 조사해야하는 노드의 인접노드들을 조사한다.
            next = v[currentIdx][i].end;
            // 조사해야하는 노드에서 인접노드의 거리정보를 가져온다.
            nextDistance = v[currentIdx][i].length;
            // printf("%d %d\n", next, nextDistance);

            int startToNextNodeDistance =
                distanceSave[currentIdx] + nextDistance;
            if (distanceSave[next] > startToNextNodeDistance) {
                distanceSave[next] = startToNextNodeDistance;
                pq.push(node(next, nextDistance));
            }
        }
    }
    return distanceSave[destination];
}

int main(int argc, char *argv[]) {
    // input
    scanf("%d %d ", &N, &M);
    int start, end, length;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &start, &end, &length);
        // 양방향 처리
        v[start].push_back(node(end, length));
        v[end].push_back(node(start, length));
    }

    for (int i = 1; i <= N; i++) {
        distanceSave[i] = 987654321;
    }

    printf("%d\n", dijkstra(1, N));
    return 0;
}