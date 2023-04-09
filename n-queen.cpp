#include <cmath>
#include <iostream>
using namespace std;

int arr[15] = {
    0,
};
int m = 0;
bool flag = false;

bool check(int cnt, int x) {
    // 지금까지 쌓아왔던 정답 array를 조사하는거임니달라.
    for (int i = 0; i < cnt; i++) {
        if (arr[i] == x || (abs(arr[i] - x) == abs(cnt - i)))
            return false;
    }
    arr[cnt] = x;
    // printf("(%d , %d)", x, cnt);
    return true;
}
void dfs(int cnt) {
    if (cnt == m) {

        flag = true;
        return;
    }
    for (int k = 0; k < m; k++) {
        if (check(cnt, k)) {
            dfs(cnt + 1);
        }
    }
}
int main() {
    scanf("%d", &m);
    // cout << many;
    for (int k = 0; k < m; k++) {
        //첫번째 행을 기준으로 돌려버리기
        arr[0] = k;
        dfs(1);

        // 출력 구문
        if (flag) {
            for (int i = 0; i < m; i++) {
                printf("%d ", arr[i] + 1);
            }
            printf("\n");
        }

        //초기화 구문
        for (int i = 0; i < m; i++) {
            arr[i] = 0;
        }
        flag = false;
    }
    // your code goes here
    return 0;
}