/*

 백준 1074
 z 분할정복
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int N, R, C;
int result = 0;
void divide(int r, int c, int size) {
    if (r == R && C == c) {
        cout << result;
        return;
    }

    // 목표값인 R C 를 찾아야하는데
    // r, c 를 통해서 옮겨다니며 조정
    if (R < r + size && R >= r && C < c + size && C >= c) {
        // 내부에서 네칸으로 나눠뻐림
        int newSize = size / 2;
        // 요거 순서가 중요함 오른쪽 갔다가 z 그리면서 내려오는 양상을 그려야
        divide(r, c, newSize);
        divide(r, c + newSize, newSize);
        divide(r + newSize, c, newSize);
        divide(r + newSize, c + newSize, newSize);
    } else {
        // 정답더했을때 올바른 값이 산출이 됨.
        // 즉 순서에 맞게 안맞으면 더해 뻐리는 로직..
        result += size * size;
    }
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> R >> C;

    divide(0, 0, (int)pow(2, N));
}
