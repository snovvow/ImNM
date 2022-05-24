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
int M;
// int P;
int distanceSave[1001];
int resultCount = 0;
struct node {
    int start;
    int end;
    int length;

    //생성자
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
    // 길이에 따른
    bool operator<(const node &b) const { return length > b.length; }
};

vector<node> v[1001];
vector<node> saveShort;
int answer[1001];

int dijkstra(int start, int destination) {
    node tmp;

    int result = 0;
    // 1을 기준으로한 거리 초기화
    for (int i = 1; i <= N; i++) {
        answer[i] = -1;
        distanceSave[i] = 9999999;
    }

    distanceSave[start] = 0;
    priority_queue<node> pq;
    tmp.end = start;
    tmp.start = start;
    tmp.length = 0;
    pq.push(tmp);

    while (!pq.empty()) {
        // 우선순위 큐에 들어간 정보를 가져온다 ( distanceSave 즉 1번 노드로부터
        // 2,3,...V 번 노드까지의 가장 짧은 거리와 관련.)

        tmp = pq.top();
        // 조사해야할 노드의 id를 가져온다
        int currentIdx = tmp.end;
        int saveStart = tmp.start;
        // printf("chekc %d", currentIdx);
        // 조사해야할 노드의 최신 거리 정보를 가져온다.
        int currentLength = tmp.length;
        // if (currentIdx != saveStart) {
        //     printf("shortest %d %d\n", saveStart, currentIdx);
        //     int flagStart = true;
        //     int flagEnd = true;

        //     for (int i = 0; i < saveShort.size(); i++) {
        //         if (saveShort[i].start == saveStart)
        //             flagStart = false;
        //         if (saveShort[i].end == currentIdx)
        //             flagEnd = false;
        //     }
        //     if (!(flagStart == false && flagEnd == false)) {
        //         saveShort.push_back(node(saveStart, currentIdx,
        //         currentLength));
        //     }
        // }
        pq.pop();
        for (int i = 0; i < v[currentIdx].size(); i++) {
            // 조사해야하는 노드의 인접노드들을 조사한다.
            int next = v[currentIdx][i].end;

            // 조사해야하는 노드에서 인접노드의 거리정보를 가져온다.
            int nextDistance = v[currentIdx][i].length;
            // printf("%d %d\n", next, nextDistance);

            int startToNextNodeDistance = currentLength + nextDistance;
            if (distanceSave[next] > startToNextNodeDistance) {
                distanceSave[next] = startToNextNodeDistance;
                answer[next] = currentIdx;
                resultCount++;
                // printf("%d %d\n", currentIdx, next);

                pq.push(node(currentIdx, next, startToNextNodeDistance));
            }
        }
    }
    return result;
}

int main(int argc, char *argv[]) {

    // input
    scanf("%d %d ", &N, &M);

    for (int i = 0; i < M; i++) {
        int start, end, length;
        scanf("%d %d %d", &start, &end, &length);

        // 양방향 처리
        v[start].push_back(node(end, length));
        v[end].push_back(node(start, length));
    }
    dijkstra(1, N);
    // for (int i = 0; i < saveShort.size(); i++) {
    //     printf("resutl %d %d\n", saveShort[i].start, saveShort[i].end);
    // }
    vector<node> result;
    for (int i = 1; i <= N; i++) {
        if (answer[i] != -1) {
            // printf("%d %d\n", i, answer[i]);
            result.push_back(node(i, answer[i]));
        }
    }
    printf("%lu\n", result.size());

    for (int i = 0; i < result.size(); i++) {
        printf("%d %d\n", result[i].end, result[i].length);
    }
}