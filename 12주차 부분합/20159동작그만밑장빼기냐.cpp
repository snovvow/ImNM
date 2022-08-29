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
int N, answer = 0;
int map[100001];
// 홀수
int odd[50001];
int even[50001];

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    int input;

    for (int i = 1; i <= N; i++) {
        cin >> input;
        map[i] = input;
    }
    // odd[1] = map[1];

    for (int i = 1; i <= N / 2; i++) {
        odd[i] = map[i * 2 - 1] + odd[i - 1];
        even[i] = map[i * 2] + even[i - 1];
        // cout << odd[i] << " " << odd[i - 1] << "odd ";
        // cout << even[i] << " " << even[i - 1] << "even ";
        // cout << endl;
    }

    int lastEvenCard = even[N / 2] - even[N / 2 - 1];
    // 홀수를 맨처음 부터 받고 그다음 짝수하는 경우
    // 0 인경운
    for (int i = 0; i <= N / 2; i++) {
        int od = odd[i];
        int ev = even[N / 2] - even[i];
        if (i != 0) {
            ev = max(ev, even[N / 2] - even[i - 1] - lastEvenCard);
        }
        int sum = od + ev;
        answer = max(sum, answer);
    }
    cout << answer;
}