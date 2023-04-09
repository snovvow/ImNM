

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int N;

int map[1001];

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    int L, H;

    for (int i = 0; i < N; i++) {
        cin >> L >> H;
        map[L] = H;
    }
    int maxIndex = 0;
    int maxHeight = 0;

    // 최대 인덱스 찾기
    for (int i = 0; i <= 1000; i++) {
        if (maxHeight <= map[i]) {
            maxHeight = map[i];
            maxIndex = i;
        }
    }

    // 왼쪽 에서부터 더하기 시작
    int maxLeftHight = 0;
    int leftSum = 0;
    for (int i = 0; i <= maxIndex; i++) {
        if (maxLeftHight <= map[i]) {
            maxLeftHight = map[i];
        }
        leftSum += maxLeftHight;
    }

    int maxRightHight = 0;
    int rightSum = 0;
    for (int i = 1000; i > maxIndex; i--) {
        if (maxRightHight <= map[i]) {
            maxRightHight = map[i];
        }
        rightSum += maxRightHight;
    }

    cout << leftSum + rightSum;
}
