#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define endl '\n'
#define maxR 7
#define maxC 8
int N, M;
// 행 렬 열 사이즈를 2를 더줘서 계산하기 편하게 함!
int MAP[maxR][maxC];
int DP[maxR][maxC][3];

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int input;

    cin >> N >> M;

    for (int i = 0; i < maxR; i++) {
        for (int k = 0; k < maxC; k++) {
            DP[i][k][0] = DP[i][k][1] = DP[i][k][2] = MAP[i][k] = 10000;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int k = 1; k <= M; k++) {
            cin >> input;

            MAP[i][k] = input;
            DP[i][k][0] = DP[i][k][1] = DP[i][k][2] = input;
        }
    }

    // // 한줄씩 나아가면서.
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {

            DP[i][j][0] =
                min(DP[i - 1][j + 1][1], DP[i - 1][j + 1][2]) + MAP[i][j];

            DP[i][j][1] = min(DP[i - 1][j][0], DP[i - 1][j][2]) + MAP[i][j];

            DP[i][j][2] =
                min(DP[i - 1][j - 1][0], DP[i - 1][j - 1][1]) + MAP[i][j];
        }
    }

    int answer = 1000000000;

    for (int k = 1; k <= M; k++) {
        answer =
            min({DP[N - 1][k][0], DP[N - 1][k][1], DP[N - 1][k][2], answer});
    }
    cout << answer;
    cout << endl;

    return 0;
}