/*

 백준 15486  문제
 퇴사 2
*/

#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

int weight[9];
int check[9];
int n, K;
int sum = 0;
int answer = 0;

void dfs(int depth) {
    if (depth == n) {
        answer++;
        return;
    }
    for (int k = 1; k <= n; k++) {
        // printf("%d %d\n", weight[k], k);

        if (check[k] == 0) {
            int checkSum = sum - K + weight[k];
            int saveSum = sum;
            // printf("%d %d %d %d \n", sum, k, checkSum, weight[k]);

            if (checkSum < 0) {
                continue;
            }
            sum = checkSum;
            check[k] = 1;
            dfs(depth + 1);
            sum = saveSum;
            check[k] = 0;
        }
    }
}

int main(int argc, char *argv[]) {

    // input
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
    }
    dfs(0);

    printf("%d\n", answer);
}