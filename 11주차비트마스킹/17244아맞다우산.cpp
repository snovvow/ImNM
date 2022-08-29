/*

 26개중 5개를 뺀 21개의 순수 영어 중에
 모든 조합돌면서 | or 연산 때려서
 50 ,49 .. 30 ~ 1 까지 모든 조합수중에서 or 연산시에
 K - 5 한값과 작거나 같은 경우를 최대의 max로 설정함.

*/

#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define endl "\n"
using namespace std;
int N, M, Answer = 10000000;
int startR, startC;
int endR, endC;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

struct Point {
    int r;
    int c;
    char type; // '#'  , 'X' , '.'
    bool visit = false;
    int depth = 0;
    // //생성자
    Point() {}

    Point(int _r, int _c, char _type, int _depth) {
        r = _r;
        c = _c;
        type = _type;
        depth = _depth;
    }
    Point(int _r, int _c, char _type) {
        r = _r;
        c = _c;
        type = _type;
    }
};

Point map[51][51];
vector<Point> shouldVisit;
vector<Point> visited;

int BFS(int startR, int startC, int endR, int endC) {

    for (int i = 0; i <= N; i++) {
        for (int k = 0; k <= M; k++) {
            map[i][k].visit = false;
        }
    }

    // cout << "check1 " << startR << " " << startC << endl;

    queue<Point> q;

    q.push(Point(startR, startC, '.', 0));
    while (!q.empty()) {
        int saveX = q.front().r;
        int saveY = q.front().c;
        int depth = q.front().depth;
        // cout << "check2 " << saveX << " " << saveY << map[saveX][saveY].type
        //      << "type" << endl;
        if (saveX == endR && saveY == endC) {
            // cout << "check3" << endl;

            return depth;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int newX = saveX + dx[i];
            int newY = saveY + dy[i];

            if (newX < 1 || newY < 1 || newX > N || newY > M) {
                continue;
            }
            if (map[newX][newY].type == '#') {
                continue;
            } else if (map[newX][newY].visit == false) {

                map[newX][newY].visit = true;

                q.push(Point(newX, newY, '.', depth + 1));
            }
        }
    }
    return 10000000;
}

// 순열 구함.
void dfs(int cnt) {
    if (cnt == shouldVisit.size()) {
        int way;
        if (shouldVisit.size() == 0) {
            way = BFS(startR, startC, endR, endC);
            Answer = min(Answer, way);
        } else {
            way = BFS(startR, startC, visited.front().r, visited.front().c);

            for (int i = 0; i < visited.size() - 1; i++) {
                // cout << "BFS"
                //      << BFS(visited[i].r, visited[i].c, visited[i + 1].r,
                //             visited[i + 1].c)
                //      << endl;

                way += BFS(visited[i].r, visited[i].c, visited[i + 1].r,
                           visited[i + 1].c);
            }
            // 끝점까지

            way += BFS(visited.back().r, visited.back().c, endR, endC);
            // cout << Answer << endl;

            Answer = min(Answer, way);
        }
        // 답 도출하기
        //시적점
        // Point tmp = visited[0] - map[startR][startC];
    }

    for (int i = 0; i < shouldVisit.size(); i++) {
        if (shouldVisit[i].visit == true)
            continue;
        shouldVisit[i].visit = true;
        visited.push_back(shouldVisit[i]);
        dfs(cnt + 1);
        visited.pop_back();
        shouldVisit[i].visit = false;
    }
}
int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M >> N;
    // input
    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= M; k++) {
            char tmp;
            cin >> tmp;
            if (tmp == 'S') {
                startR = i;
                startC = k;
                tmp = '.';
            } else if (tmp == 'E') {
                endR = i;
                endC = k;
                tmp = '.';
            } else if (tmp == 'X') {
                shouldVisit.push_back(Point(i, k, 'X'));
            }
            map[i][k] = Point(i, k, tmp, 0);
        }
    }
    // for (int i = 0; i < shouldVisit.size(); i++) {
    //     cout << shouldVisit[i].r << ',' << shouldVisit[i].c << endl;
    // }
    dfs(0);
    cout << Answer << endl;
}
