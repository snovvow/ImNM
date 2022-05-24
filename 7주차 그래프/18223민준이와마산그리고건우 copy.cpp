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
int V;
int E;
int P;
int distanceSave[5001];

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

vector<node> v[5001];

int dijkstra(int start, int destination) {
    node tmp;

    int result = 0;
    // 1을 기준으로한 거리 초기화
    for (int i = 1; i <= V; i++) {

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

// . (2 ≤ V  ≤ 5,000, 1 ≤ E ≤ 10,000, 1 ≤ P  ≤ V)

int main(int argc, char *argv[]) {

    // input
    scanf("%d %d %d", &V, &E, &P);

    for (int i = 0; i < E; i++) {
        int start, end, length;
        scanf("%d %d %d", &start, &end, &length);

        // 양방향 처리
        v[end].push_back(node(start, length));
        v[start].push_back(node(end, length));
    }

    // 1 노드로부터 목적지까지 최단거리 ( distance[V]) 가 답이될꺼임.!

    int goMasanDirect = dijkstra(1, V);
    int saveGunwu = dijkstra(1, P) + dijkstra(P, V);
    if (goMasanDirect == saveGunwu) {
        printf("SAVE HIM");
    } else {
        printf("GOOD BYE");
    }
}