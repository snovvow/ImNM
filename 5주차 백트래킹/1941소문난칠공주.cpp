/*

 백준 15486  문제
 퇴사 2
*/

#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
int dR[4] = {0, 1, -1, 0};
int dC[4] = {1, 0, 0, -1};
bool check[6][6];
int SY[6][6];
int answer;

bool path(int r, int c, int num) {
    if (num == 7) {
        return true;
    }
    bool flag = false;
    for (int i = 0; i < 4; i++) {
        int newR = r + dR[i];
        int newC = c + dC[i];
        if (newR < 1 || newR > 5 || newC < 1 || newC > 5) {
            continue;
        }
        if (check[newR][newC]) {
            flag = true;
            path(newR, newC, num + 1);
        }
    }
    // if (!flag)
    return false;
}

bool checkConnected() {

    for (int i = 1; i <= 5; i++) {
        for (int k = 1; k <= 5; k++) {
            if (path(i, k, 1))
                return true;
        }
    }
    return false;
}

// 배열 조합? -> num 25이면 인접한지만 조사하면됨.
void dfs(int num, int YCount) {
    int r = num / 5 + 1;
    int c = num % 5 + 1;
    printf("%d %d %d\n", r, c, YCount);
    // if (YCount >= 4) {
    //     dfs(num + 1, saveY);
    //     return;
    // }
    if (num == 25) {
        // 인접한지 체크
        for (int i = 1; i <= 5; i++) {
            for (int k = 1; k <= 5; k++) {
                printf("%d", check[i][k]);
            }
            printf("\n");
        }
        printf("\n");
        // if (checkConnected()) {
        //     answer++;
        // }
        return;
    }
    int saveY = YCount;
    if (SY[r][c] == 1)
        saveY++;
    check[r][c] = true;
    dfs(num + 1, saveY);
    check[r][c] = false;
}

int main(int argc, char *argv[]) {

    // input
    for (int i = 1; i <= 5; i++) {
        for (int k = 1; k <= 5; k++) {
            char c;
            scanf("\n%c", &c);
            if (c == 'Y') {
                //임도연 3명 Y임도연 1
                SY[i][k] = 1;
            }
        }
    }

    // for (int i = 1; i <= 5; i++) {
    //     for (int k = 1; k <= 5; k++) {
    //         printf("%d", SY[i][k]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    int saveY = 0;
    if (SY[1][1] == 1)
        saveY++;
    check[1][1] = true;
    dfs(0, saveY);
    check[1][1] = false;
    // dfs(1, 0);

    printf("%d\n", answer);
}
