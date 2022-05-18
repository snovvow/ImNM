/*

 백준 15486  문제
 퇴사 2
*/

#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <vector>
using namespace std;
int L;
int C;
char password[15];
char alphabet[26];
bool check[26];

// void dfs(int depth) {
//     if (depth == k) {
//         // save max , min num
//         long numSave = 0;
//         for (int i = k; i >= 0; i--) {
//             // 자릿수 별로 비교 맨처음
//             numSave += (long)pow(10, i) * saveNum[k - i];
//         }
//         if (minCheck > numSave) {
//             minCheck = numSave;
//             for (int i = 0; i <= k; i++) {
//                 // 자릿수 별로 비교 맨처음
//                 minNum[i] = saveNum[i];
//             }
//         }
//         if (maxCheck < numSave) {
//             maxCheck = numSave;
//             for (int i = 0; i <= k; i++) {
//                 // 자릿수 별로 비교 맨처음
//                 maxNum[i] = saveNum[i];
//             }
//         }
//         // printf("%d %d", numSave, (int)pow(10, 0));

//         // printf("\n");
//         // 최대 최소 찾기

//         return;
//     }

//     for (int i = 0; i <= 9; i++) {
//         if (check[i] == true) {
//             continue;
//         }

//         if (ies[depth] == '>') {
//             if (saveNum[depth] > i) {
//                 check[i] = true;
//                 saveNum[depth + 1] = i;
//                 dfs(depth + 1);
//                 check[i] = false;
//             }
//         }
//         if (ies[depth] == '<') {
//             if (saveNum[depth] < i) {
//                 saveNum[depth + 1] = i;
//                 check[i] = true;
//                 dfs(depth + 1);
//                 check[i] = false;
//             }
//         }
//     }
// }

void dfs(int depth) {
    if (depth == L - 1) {
        //최소 한개 두개 체크
        int moCount = 0;
        int zaCount = 0;
        for (int i = 0; i < L; i++) {
            if (password[i] == 'a' || password[i] == 'e' ||
                password[i] == 'i' || password[i] == 'o' ||
                password[i] == 'u') {
                moCount++;
            } else {
                zaCount++;
            }
        }

        if (zaCount >= 2 && moCount >= 1) {
            for (int i = 0; i < L; i++) {
                printf("%c", password[i]);
            }
            printf("\n");
        }

        return;
    }

    for (int i = 0; i < C; i++) {
        if (check[i] == true) {
            continue;
        }

        // 넘어가기전에 문자 작은지 체크
        if (password[depth] < alphabet[i]) {
            check[i] = true;
            password[depth + 1] = alphabet[i];
            dfs(depth + 1);
            check[i] = false;
        }
    }
}

int main(int argc, char *argv[]) {

    // input
    scanf("%d %d", &L, &C);

    for (int i = 0; i < C; i++) {
        scanf("\n%c", &alphabet[i]);
    }

    sort(alphabet, alphabet + C);

    for (int i = 0; i < C; i++) {
        check[i] = true;
        password[0] = alphabet[i];
        dfs(0);
        check[i] = false;
    }
}