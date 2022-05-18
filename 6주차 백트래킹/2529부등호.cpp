/*

 백준 15486  문제
 퇴사 2
*/

#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <vector>
using namespace std;
int k;
char ies[10];
bool check[10];
int maxNum[11];
int minNum[11];
long maxCheck = 0;
long minCheck = 99999999999;
int saveNum[11];

void dfs(int depth) {
    if (depth == k) {
        // save max , min num
        long numSave = 0;
        for (int i = k; i >= 0; i--) {
            // 자릿수 별로 비교 맨처음
            numSave += (long)pow(10, i) * saveNum[k - i];
        }
        if (minCheck > numSave) {
            minCheck = numSave;
            for (int i = 0; i <= k; i++) {
                // 자릿수 별로 비교 맨처음
                minNum[i] = saveNum[i];
            }
        }
        if (maxCheck < numSave) {
            maxCheck = numSave;
            for (int i = 0; i <= k; i++) {
                // 자릿수 별로 비교 맨처음
                maxNum[i] = saveNum[i];
            }
        }
        // printf("%d %d", numSave, (int)pow(10, 0));

        // printf("\n");
        // 최대 최소 찾기

        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (check[i] == true) {
            continue;
        }

        if (ies[depth] == '>') {
            if (saveNum[depth] > i) {
                check[i] = true;
                saveNum[depth + 1] = i;
                dfs(depth + 1);
                check[i] = false;
            }
        }
        if (ies[depth] == '<') {
            if (saveNum[depth] < i) {
                saveNum[depth + 1] = i;
                check[i] = true;
                dfs(depth + 1);
                check[i] = false;
            }
        }
    }
}

int main(int argc, char *argv[]) {

    // input
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        scanf("\n%c", &ies[i]);
    }

    // for (int i = 0; i <= 9; i++) {
    //     printf("%c", ies[i]);
    // }

    for (int i = 0; i <= 9; i++) {
        saveNum[0] = i;
        check[i] = true;
        dfs(0);
        check[i] = false;
    }

    for (int i = 0; i <= k; i++) {
        printf("%d", maxNum[i]);
    }
    printf("\n");

    for (int i = 0; i <= k; i++) {
        printf("%d", minNum[i]);
    }
}