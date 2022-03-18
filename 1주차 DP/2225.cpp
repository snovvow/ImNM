/*

 백준 2225 문제
 DP
*/
#include <algorithm>
#include <stdio.h>
using namespace std;
int main(int argc, char *argv[]) {
    int n, k;
    scanf("%d %d", &n, &k);

    long long dp[201] = {0};

    for (int k = 0; k <= 200; k++) {
        dp[k] = 1;
    }

    for (int i = 2; i <= k; i++) {
        // 0 도 포함 위에서 아래로 더하기만
        for (int j = 1; j <= n + 1; j++) {

            dp[j] = dp[j] + dp[j - 1];
            // printf("%lld ", dp[j]);

            // 모드 아래로 내려야함
            dp[j] = dp[j] % 1000000000;
        }
        // printf("\n");
    }

    printf("%lld", dp[n]);
}