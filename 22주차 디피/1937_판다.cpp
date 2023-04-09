#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int N, M, ans, sum;
int map[501][501];
int dp[501][501];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int DFS(int x, int y) {
    // dp에 저장된 값이 있을 경우 그 값을 반환.
    if (dp[x][y] != 0) {
        return dp[x][y];
    }

    // 판다가 대나무 숲에서 최소한 1년은 살 수 있으므로
    // dp[x][y] = 1로 초기화 할 수 있음.
    dp[x][y] = 1;

    int newX, newY;
    // 상하좌우 검사.
    for (int i = 0; i < 4; i++) {
        newX = x + dx[i];
        newY = y + dy[i];

        // 범위에서 벗어났을 경우 continue.
        if (newX < 0 || newY < 0 || newX >= N || newY >= N) {
            continue;
        }

        // 현재 대나무 숲보다 더 많은 양의 대나무가 있는 경우.
        if (map[x][y] < map[newX][newY]) {
            // 상하좌우 중에서 가장 오랫동안 생존할 수 있는 기간을 계산한다.
            dp[x][y] = max(dp[x][y], DFS(newX, newY) + 1);
        }
    }
    return dp[x][y];
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans = max(ans, DFS(i, j));
        }
    }

    cout << ans;
}