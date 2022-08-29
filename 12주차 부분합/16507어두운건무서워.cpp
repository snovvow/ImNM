/*

 26개중 5개를 뺀 21개의 순수 영어 중에
 모든 조합돌면서 | or 연산 때려서
 50 ,49 .. 30 ~ 1 까지 모든 조합수중에서 or 연산시에
 K - 5 한값과 작거나 같은 경우를 최대의 max로 설정함.

*/

#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#define endl "\n"
using namespace std;
int N, M;
int K;

int map[1025][1025];
int sumMap[1025][1025];

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    int input;

    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= M; k++) {
            cin >> input;
            map[i][k] = input;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= M; k++) {
            sumMap[i][k] = map[i][k] + sumMap[i][k - 1] + sumMap[i - 1][k] -
                           sumMap[i - 1][k - 1];
        }
    }
    int r1, c1, r2, c2;

    for (int i = 1; i <= K; i++) {
        cin >> r1 >> c1 >> r2 >> c2;

        int sum = sumMap[r2][c2] - sumMap[r1 - 1][c2] - sumMap[r2][c1 - 1] +
                  sumMap[r1 - 1][c1 - 1];
        int size = (r2 - r1 + 1) * (c2 - c1 + 1);
        int asw = sum / size;
        cout << asw << endl;
    }
}