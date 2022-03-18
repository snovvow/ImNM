
#include <stdio.h>

int main(int argc, char *argv[]) {
    int n, m;
    scanf("%d %d", &n, &m);

    int candy[1000000];

    // 입력받기
    for (int i = 0; i < n * m; i++) {
        scanf("%d", &candy[i]);
    }

    // for (int i = 0; i < n; i++) {
    //     for (int k = 0; k < m; k++) {
    //         printf("%d (%d)", candy[i * m + k]);
    //     }
    //     printf("\n");
    // }

    // 첫번째줄

    for (int i = 1; i < m; i++) {
        candy[i] = candy[i] + candy[i - 1];
    }
    // 두번째줄 부터
    for (int i = m; i < n * m; i++) {

        int max;
        if (i % m == 0)
            max = candy[i - m];
        else if (candy[i - 1] > candy[i - m])
            max = candy[i - 1];
        else
            max = candy[i - m];

        candy[i] = candy[i] + max;
    }

    // for (int i = 0; i < n; i++) {
    //     for (int k = 0; k < m; k++) {
    //         printf("%d ", candy[i * m + k]);
    //     }
    //     printf("\n");
    // }

    printf("%d", candy[n * m - 1]);
}