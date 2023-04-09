#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int R, C;

char inputMap[21][21];

int dR[4] = {0, 1, -1, 0};
int dC[4] = {1, 0, 0, -1};
int maxResult = 0;
map<char, int> m;

void dfs(int r, int c, int depth) {
    // cout << "in"
    //      << "(" << r << "," << c << ")" << inputMap[r][c] << endl;

    // 최댓값 갱신
    if (maxResult < depth) {
        maxResult = depth;
    }

    for (int i = 0; i < 4; i++) {
        int newR = r + dR[i];
        int newC = c + dC[i];

        if (newR < 1 || newR > R || newC < 1 || newC > C)
            continue;
        // 두번이상 지나가는 지 체크
        char value = inputMap[newR][newC];
        // cout << "(" << newR << "," << newC << ")" << inputMap[newR][newC]
        //      << m[value] << endl;
        if (m[value] == 1)
            continue;

        // 두번 안지나가면 고고
        m[value]++;
        dfs(newR, newC, depth + 1);
        m[value]--;

        // 초기화?
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C;

    for (char i = 'A'; i <= 'Z'; i++) {
        m[i] = 0;
    }

    for (int i = 1; i <= R; i++) {
        string a;
        cin >> a;

        for (int k = 0; k < a.length(); k++) {
            inputMap[i][k + 1] = a[k];
        }
    }
    m[inputMap[1][1]] = 1;

    dfs(1, 1, 1);

    cout << maxResult;
}
