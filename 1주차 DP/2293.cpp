/*

 백준 2293 문제
 DP
*/
#include <algorithm>
#include <stdio.h>
using namespace std;
int main(int argc, char *argv[]) {
    int n, k;
    scanf("%d %d", &n, &k);
    int coin[101];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &coin[i]);
    }

    int count[10001] = {0};
    count[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = coin[i]; j <= k; j++) {
            count[j] = count[j] + count[j - coin[i]];
        }
    }

    printf("%d", count[k]);
}