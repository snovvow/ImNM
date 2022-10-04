#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define endl '\n'
#define maxR 7
#define maxC 8
int H, W;
int T;
// 행 렬 열 사이즈를 2를 더줘서 계산하기 편하게 함!
int map[500];

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int answer = 0;

    cin >> H >> W;
    for (int i = 0; i < W; i++) {
        cin >> map[i];
    }
    for (int i = 1; i < W - 1; i++) {
        int left = 0;
        int right = 0;
        //왼쪽 최대 값
        for (int j = 0; j < i; j++)
            left = max(left, map[j]);
        //오른쪽 최대 값
        for (int j = W - 1; j > i; j--)
            right = max(right, map[j]);
        //빗물 계산
        answer += max(0, min(left, right) - map[i]);
    }

    cout << answer << endl;
}
