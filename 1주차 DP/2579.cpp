/*

 백준 2579 문제
 O(n) 풀이
 DP
*/
#include <algorithm>
#include <stdio.h>
using namespace std;
int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);

    int score[300];
    int sum[300];
    for (int i = 0; i < n; i++) {
        scanf("%d", &score[i]);
    }
    sum[0] = score[0];
    sum[1] = score[0] + score[1];
    sum[2] = max(score[0] + score[2], score[1] + score[2]);

    for (int i = 3; i < n; i++) {
        sum[i] = max(sum[i - 2], sum[i - 3] + score[i - 1]) + score[i];
    }
    printf("%d", sum[n - 1]);
}