/*

 백준 1915 문제
 O(n) 풀이
 DP
*/
#include <algorithm>
#include <stdio.h>
using namespace std;
int main(int argc, char *argv[]) {
    int n, m;
    scanf("%d %d", &n, &m);

    int square[1000000];
    // 입력받기 평탄화 해서 받음
    for (int i = 0; i < n * m; i++) {
        scanf("%1d", &square[i]);
    }
    // 두번째줄 부터
    for (int i = m; i < n * m; i++) {

        int max;
        // 첫번째 행일 때 ( 위쪽에서만 내려옴 ) 스킵
        if (i % m == 0)
            continue;
        // 두번째 행일때부터
        // 대각선 위 , 왼쪽 , 위 방향 이 다 0이 아닐때
        else if (square[i - 1] != 0 && square[i - m] != 0 &&
                 square[i - m - 1] != 0 && square[i] == 1) {
            // 반례있어서 세개중 최소값에 +1하는 형태로 바꿈
            int minNum =
                min(square[i - 1], min(square[i - m], square[i - m - 1]));
            square[i] = minNum + 1;
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int k = 0; k < m; k++) {
    //         printf("%d ", square[i * m + k]);
    //     }
    //     printf("\n");
    // }
    // 정답 출력
    int max = -100000;
    for (int i = 0; i < n * m; i++) {
        if (max < square[i])
            max = square[i];
    }
    // 제곱 해서 출력
    printf("%d", max * max);
}