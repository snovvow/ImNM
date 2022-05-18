/*

 백준 15486  문제
 퇴사 2
*/

#include <algorithm>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;
int N;
int M;
int H;
int map[11][11];
char visit[11][11];
int zinwuR;
int zinwuC;
int homeR;
int homeC;
int result = 0;
int milkCount = 0;
//상하좌우
int dR[4] = {1, 0, -1, 0};
int dC[4] = {0, 1, 0, -1};

// void dfs(int r, int c, int health, int eatCount) {

//     if (health == 0 || eatCount == milkCount ||
//         (r == homeR && c == homeC && eatCount > 0)) {
//         if (r == homeR && c == homeC) {
//             result = max(result, eatCount);
//         }

//         return;
//         // 정답 출력
//     }

//     for (int i = 0; i < 4; i++) {
//         int newR = r + dR[i];
//         int newC = c + dC[i];

//         // 맵 범위를 벗어나면

//         if (newR < 1 || newR > N || newC < 1 || newC > N) {
//             continue;
//         }
//         if (visit[newR][newC] == true) {
//             continue;
//         }
//         // 민초우유를 만나면

//         if (map[newR][newC] == 2) {
//             map[newR][newC] = 0;
//             printf("%d %d", newR, newC);
//             visit[newR][newC] = true;

//             dfs(newR, newC, health - 1 + H, eatCount + 1);
//             visit[newR][newC] = false;

//             map[newR][newC] = 2;

//         } else {
//             visit[newR][newC] = true;

//             dfs(newR, newC, health - 1, eatCount);
//             visit[newR][newC] = false;
//         }
//     }
// }

struct mint {
    int mintR;
    int mintC;
    bool visit;
    //생성자
    mint(int _mintR, int _mintC) {
        mintR = _mintR;
        mintC = _mintC;
        visit = false;
    }
};
vector<mint> mintArray;

void dfs(int r, int c, int num, int health) {

    int toHomeDistance = abs(r - homeR) + abs(c - homeC);
    //정답 찾기
    int checkHomeHealth = health - toHomeDistance;
    if (checkHomeHealth >= 0) {
        result = max(result, num);
    }
    // printf("%d %d %d %d\n", r, c, num, health);
    if (num >= mintArray.size()) {
        return;
    }
    // return;
    // }
    for (int i = 0; i < mintArray.size(); i++) {
        // 이미 방문한  우유이면
        if (mintArray[i].visit == true) {
            continue;
        }
        int distance =
            abs(mintArray[i].mintR - r) + abs(mintArray[i].mintC - c);
        if (distance > health) {
            continue;
        }
        int newHealth = health - distance + H;

        mintArray[i].visit = true;
        dfs(mintArray[i].mintR, mintArray[i].mintC, num + 1, newHealth);
        mintArray[i].visit = false;
    }
}
int main(int argc, char *argv[]) {

    // input
    scanf("%d %d %d", &N, &M, &H);

    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= N; k++) {
            scanf("%d", &map[i][k]);
            if (map[i][k] == 1) {
                homeR = i;
                homeC = k;
            }
            if (map[i][k] == 2) {
                mintArray.push_back(mint(i, k));
                milkCount++;
            }
        }
    }

    dfs(homeR, homeC, 0, M);

    printf("%d", result);
}