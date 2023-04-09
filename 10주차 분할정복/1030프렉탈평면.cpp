/*

 백준 1074
 z 분할정복
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int S, N, K, R1, R2, C1, C2;
int result = 0;
int printByrAndc(int r, int c, int len) {
    if (len == 1) {
        return 0;
    }

    // N 으로 나눠주는 이유는 애초에 len 이 N^S 임 그래서 N으로 나눠주면서
    // 시간을 까면서 들어가는겨.
    int border = len / N;
    int left = (N - K) / 2;
    int right = (N + K) / 2;
    if (r >= border * left && r < border * right && c >= border * left &&
        c < border * right) {
        return 1;
    }
    // 정답을 못정했으면패스
    // 사실상 프랙탈을 이미 만들었다고 가정하는거임
    // N= 5 이고 k =3 이면 s= 1 일때
    // 가운데가 3*3 이고 전체가 5*3 이되는거...
    // 즉 사실 중요한건 가운데에 속해있으면 무조건 1이고
    // 가운데 부분이 아니면 좀더 재귀호출해서 한번더 깊게 들어가봐야 안다...
    // 이거임!

    return printByrAndc(r % border, c % border, border);
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // s n k r1 r2 c1 c2
    cin >> S >> N >> K >> R1 >> R2 >> C1 >> C2;
    // 시간값은 이미 정해졌으므로
    // 해당하는 시간값으로 프렉탈의 가로세로 길이를 구할 수있다.
    int len = (int)pow(N, S);

    for (int i = R1; i <= R2; i++) {
        for (int k = C1; k <= C2; k++) {
            cout << printByrAndc(i, k, len);
        }
        cout << endl;
    }
}
