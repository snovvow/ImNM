/*

 백준 15486  문제
 퇴사 2
*/

#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
int dR[2] = {0, 1};
int dC[2] = {1, 0};
bool check[26][26];
bool visit[26][26];

int R, C;
int answer = 0;

bool checkCanPlace(int r, int c) {
    return check[r - 1][c - 1] && check[r - 1][c] && check[r][c - 1];
}

void dfs(int num) {
    // if (checkCanPlace(r, c)) {
    //     return;
    // }
    int r = num / C + 1;
    int c = num % C + 1;
    if (num == R * C) {
        answer++;
        for (int i = 1; i <= R; i++) {
            for (int k = 1; k <= C; k++) {
                // printf("%d", check[i][k]);
            }
            // printf("\n");
        }
        // printf("answer (%d %d)\n", r, c);
        // printf("\n");

        return;
    }

    if (checkCanPlace(r, c)) {
        // 여기 부분 이해 안감.
        dfs(num + 1);
        return;
    }

    dfs(num + 1);
    check[r][c] = true;
    dfs(num + 1);
    check[r][c] = false;
}

int main(int argc, char *argv[]) {

    // input
    scanf("%d %d", &R, &C);
    check[1][1] = true;
    dfs(1);
    check[1][1] = false;
    dfs(1);

    printf("%d\n", answer);
}