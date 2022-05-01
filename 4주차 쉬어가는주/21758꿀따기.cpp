/*

 백준 15486  문제
 퇴사 2
*/

#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

int sum[100001];
int honey[100001];

int main(int argc, char *argv[]) {

    // test case
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &honey[i]);
        sum[i] = sum[i - 1] + honey[i];
    }
    int result = 0;
    for (int i = 2; i <= n - 1; i++) {
        // 통 벌 벌
        result = max(result, sum[i - 1] + sum[n - 1] - honey[i]);
        // 벌 벌 통
        result = max(result, sum[n] - honey[1] - honey[i] + sum[n] - sum[i]);
        // 벌 통 벌
        result = max(result, sum[i] - honey[1] + sum[n - 1] - sum[i - 1]);
    }

    printf("%d\n", result);
}