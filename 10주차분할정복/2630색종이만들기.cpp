/*

 백준 1074
 z 분할정복
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int N;
int arr[128][128];
int whiteCount = 0;
int blueCount = 0;

bool checkType(int r, int c, int size) {
    int save = arr[r][c];
    for (int i = r; i < r + size; i++) {
        for (int k = c; k < c + size; k++) {
            if (save != arr[i][k]) {
                return false;
            }
        }
    }
    return true;
}

void divide(int r, int c, int size) {
    if (size == 1) {
        if (arr[r][c] == 1) {
            blueCount++;
        } else {
            whiteCount++;
        }
        return;
    }

    // 목표값인 R C 를 찾아야하는데
    // r, c 를 통해서 옮겨다니며 조정
    if (!checkType(r, c, size)) {
        // 내부에서 네칸으로 나눠뻐림
        int newSize = size / 2;
        divide(r, c, newSize);
        divide(r, c + newSize, newSize);
        divide(r + newSize, c, newSize);
        divide(r + newSize, c + newSize, newSize);
    } else {
        if (arr[r][c] == 1) {
            blueCount++;
        } else {
            whiteCount++;
        }
    }
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            cin >> arr[i][k];
        }
    }

    divide(0, 0, N);
    cout << whiteCount << "\n";
    cout << blueCount;
}
