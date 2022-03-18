/*

 백준 11048 문제
 O(n) 풀이

*/
#include <stdio.h>

int main(int argc, char *argv[]) {
    int n, m;
    scanf("%d %d", &n, &m);

    int candy[1000000];
    // 입력받기 평탄화 해서 받음
    for (int i = 0; i < n * m; i++) {
        scanf("%d", &candy[i]);
    }
    // 첫번째줄
    for (int i = 1; i < m; i++) {
        candy[i] = candy[i] + candy[i - 1];
    }
    // 두번째줄 부터
    for (int i = m; i < n * m; i++) {
        // 대각선 방향은 애초에 생각을 안함 왼쪽또는 위쪽에서 오는 방향만 생각
        int max;
        // 첫번째 행일 때 ( 위쪽에서만 내려옴 )
        if (i % m == 0)
            max = candy[i - m];
        // 두번째 행일때부터

        // 왼쪽의 값이 더 클 때
        else if (candy[i - 1] > candy[i - m])
            max = candy[i - 1];
        // 위쪽의 값이 더 클 때
        else
            max = candy[i - m];
        // max값을 계속 더해나감
        candy[i] = candy[i] + max;
    }
    // 정답 출력
    printf("%d", candy[n * m - 1]);
}