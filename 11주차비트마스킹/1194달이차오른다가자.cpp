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
    char type; // '#' ,'a' , 'X' , '.' , 'A'
    int visit = 0;

    // //생성자
    Point() {}
    Point(int _r, int _c, char _type) {
        r = _r;
        c = _c;
        type = _type;
    }
};

Point map[51][51];
// 1인 위치..?
vector<Point> shouldVisit;
vector<char> myKey;

bool isEnd(int r, int c) {
    bool check = false;
    for (int i = 0; i < shouldVisit.size(); i++) {
        if (shouldVisit[i].r == r && shouldVisit[i].c == c)
            check = true;
    }
    return check;
}

bool canOpenDoor(int r, int c) {
    bool check = false;
    for (int i = 0; i < myKey.size(); i++) {
        if ((myKey[i] - 32) == map[r][c].type)
            check = true;
    }
    return check;
}
// 순열 구함.
void dfs(int r, int c, int cnt) {
    if (isEnd(r, c)) {
        Answer = min(Answer, cnt);
    }
    for (int i = 0; i < 4; i++) {
        int newX = r + dx[i];
        int newY = c + dy[i];

        if (newX < 1 || newY < 1 || newX > N || newY > M) {
            continue;
        }
        if (map[newX][newY].type == '#') {
            continue;
        }
        if ('A' <= map[newX][newY].type && 'F' >= map[newX][newY].type) {
            if (!canOpenDoor(newX, newY)) {
                continue;
            }
        }

        if (map[newX][newY].visit < 4) {
            if ('a' <= map[newX][newY].type && 'f' >= map[newX][newY].type) {
                myKey.push_back(map[newX][newY].type);
            }
            // cout << newX << ',' << newY << endl;
            map[newX][newY].visit++;

            dfs(newX, newY, cnt + 1);
            if ('a' <= map[newX][newY].type && 'f' >= map[newX][newY].type) {
                myKey.pop_back();
            }
            map[newX][newY].visit--;
        }
    }
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    // input
    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= M; k++) {
            char tmp;
            cin >> tmp;
            if (tmp == '0') {
                startR = i;
                startC = k;
                tmp = '.';
            } else if (tmp == '1') {
                shouldVisit.push_back(Point(i, k, '1'));
                tmp = '.';
            }
            map[i][k] = Point(i, k, tmp);
        }
    }
    // for (int i = 0; i < shouldVisit.size(); i++) {
    //     cout << shouldVisit[i].r << ',' << shouldVisit[i].c << endl;
    // }
    dfs(startR, startC, 0);
    if (Answer == 10000000) {
        cout << "-1" << endl;
        return 0;
    }
    cout << Answer << endl;
}
