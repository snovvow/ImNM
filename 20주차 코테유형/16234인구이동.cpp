#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int map[51][51];
int map_temp[51][51];
int visited[51][51];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
int N, L, R;

// 인구차가 L명 이상 R명 이하라면.
// 국경선을 하루동안 연다.
// 연합 인구수 / 연합 이루고 있는 칸의 개수.
// 국경선을 먼저.. 열어야함? 매번 그러면 소숫점 날라갈 것 같음.

struct Point {
    int r;
    int c;
    Point(int _r, int _c) {
        r = _r;
        c = _c;
    }
};
queue<Point> q;

int BFS() {
    int sum_union = 0;
    int divide = 0;
    int flag = 0;
    vector<Point> v;

    while (!q.empty()) {
        Point cur = q.front();
        sum_union += map[cur.r][cur.c];
        v.push_back(cur);
        q.pop();
        for (int i = 0; i < 4; i++) {
            Point next = Point(cur.r + dr[i], cur.c + dc[i]);

            if (next.r >= 0 && next.r < N && next.c >= 0 && next.c < N)
                continue;
            if (visited[next.r][next.c] == 0) {
                int dif = abs(map[cur.r][cur.c] - map[next.r][next.c]);
                if (dif >= L && dif <= R) {
                    visited[next.r][next.c] = 1;
                    flag = 1;
                    q.push(next);
                }
            }
        }
    }

    divide = (int)(sum_union / v.size());

    for (int i = 0; i < v.size(); i++) {
        Point temp = v[i];
        map_temp[temp.r][temp.c] = divide;
    }

    return flag;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // input
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            cin >> map[i][k];
            map_temp[i][k] = map[i][k];
        }
    }

    int days = 0;
    while (1) {
        int flag = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j] == 0) {
                    Point cur = Point(i, j);
                    q.push(cur);
                    visited[i][j] = 1;
                    flag += BFS();
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                map[i][j] = map_temp[i][j];
                visited[i][j] = 0;
            }
        }

        if (flag == 0) {
            cout << days;
            break;
        }
        days++;
    }

    return 0;
}