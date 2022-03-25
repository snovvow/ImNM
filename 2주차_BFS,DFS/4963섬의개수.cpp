/*

 백준 2606 문제
 바이러스
*/

#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> v[101];
bool ch[101] = {
    false,
};
int cnt = 0;

void DFS(int k) {

    for (int i = 0; i < v[k].size(); i++) {
        ch[k] = true;
        // printf("(%d -> %d)", k, v[k][i]);

        if (ch[v[k][i]] == false) {
            cnt++;
            DFS(v[k][i]);
        }
    }
}

int main(int argc, char *argv[]) {
    int n, k;

    scanf("%d", &n);
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        //양방향
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
    // input

    DFS(1);

    // output
    printf("%d", cnt);
}