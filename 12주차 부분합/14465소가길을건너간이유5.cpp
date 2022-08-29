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
int N, K, B, answer = 1000000;
bool map[100001];

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K >> B;
    int input;

    for (int i = 0; i < B; i++) {
        cin >> input;

        map[input] = true;
    }
    int cnt = 0;
    for (int i = 1; i <= K; i++) {
        cnt += map[i];
    }

    int j = 1;
    answer = cnt;
    for (int i = K + 1; i <= N; i++) {
        cnt -= map[j++];
        cnt += map[i];
        answer = min(answer, cnt);
    }

    cout << answer;
}