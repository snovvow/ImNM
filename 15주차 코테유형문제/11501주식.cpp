#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define endl '\n'
#define maxR 7
#define maxC 8
int N, M;
int T;
// 행 렬 열 사이즈를 2를 더줘서 계산하기 편하게 함!
int MAP[maxR][maxC];
int DP[maxR][maxC][3];

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int input;

    cin >> T;
    // 0 주식 하나사기
    // 1 가지고 있는 주식 팔기... 원하는 만큼이라니?
    // 2 아무것도 안하기
    while (T > 0) {
        int N;
        cin >> N;

        int map[1000000];
        for (int i = 0; i < N; i++) {
            cin >> map[i];
        }
        int max = 0;
        long long sum = 0;

        for (int i = N - 1; i >= 0; i--) {
            if (max < map[i]) {
                max = map[i];
            } else {
                sum += (max - map[i]);
            }
        }

        cout << sum << endl;
        T--;
    }
}