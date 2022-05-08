/*

 백준 15486  문제
 퇴사 2
*/

#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

int s[21][21];
int check[21];
int N, K;
int sum = 0;
int answer = 10000000;
int sumAll = 0;

void dfs(int depth, int next) {
    if (depth == N / 2) {
        int start = 0;
        int link = 0;

        for (int i = 1; i <= N; i++) {
            if (check[i] == 0) {
                for (int k = 1; k <= N; k++) {
                    if (check[k] == 0) {
                        // printf("link(%d %d)", i, k);
                        link += s[i][k];
                    }
                }
            } else {
                for (int k = 1; k <= N; k++) {
                    if (check[k] != 0) {
                        // printf("start(%d %d)", i, k);
                        start += s[i][k];
                    }
                }
            }
        }
        // printf("\n");

        // printf("%d %d\n", start, link);

        answer = min(answer, abs(start - link));
        return;
    }
    for (int k = next; k <= N; k++) {

        if (check[k] == 1) {
            continue;
        }
        // printf("(%d)", k);

        check[k] = 1;
        dfs(depth + 1, k + 1);
        check[k] = 0;
    }
}

int main(int argc, char *argv[]) {

    // input
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= N; k++) {
            scanf("%d", &s[i][k]);
            sumAll += s[i][k];
        }
    }
    dfs(0, 1);

    printf("%d\n", answer);
}