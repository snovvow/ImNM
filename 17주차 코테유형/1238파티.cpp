#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int N, M, X;
int distanceSave[1001];
int resultArr[1001];
struct node {
    int end;
    int length;

    //생성자
    node() {}
    node(int _end, int _length) {
        end = _end;
        length = _length;
    }
    // 길이에 따른
    bool operator<(const node &b) const { return length > b.length; }
};

vector<node> v[1001];

int dijkstra(int start, int destination) {
    node tmp;

    int result = 0;
    // 1을 기준으로한 거리 초기화
    for (int i = 1; i <= N; i++) {
        distanceSave[i] = 9999999;
    }

    distanceSave[start] = 0;
    priority_queue<node> pq;
    tmp.end = start;
    tmp.length = 0;
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
                // printf("visit %d %d\n", next, nextDistance);

                distanceSave[next] = startToNextNodeDistance;
                pq.push(node(next, startToNextNodeDistance));
            }
        }
    }
    return result;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> X;
    int start, end, length;

    for (int i = 0; i < M; i++) {
        cin >> start >> end >> length;
        // 단반향 처리
        v[start].push_back(node(end, length));
    }

    for (int i = 1; i <= N; i++) {
        resultArr[i] = dijkstra(i, X);
    }
    for (int i = 1; i <= N; i++) {
        resultArr[i] += dijkstra(X, i);
    }
    int result = -1;
    for (int i = 1; i <= N; i++) {
        result = max(result, resultArr[i]);
    }
    cout << result;
}
