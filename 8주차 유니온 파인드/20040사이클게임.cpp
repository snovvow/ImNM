/*

 백준 20040  사이클 게임

*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;
int M;
int parent[500001];
int cycleCount[500001];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return true;

    parent[y] = x;
    return false;
}

bool isUnion(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return true;
    return false;
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    int start, end;
    for (int i = 0; i <= N - 1; i++) {
        parent[i] = i;
    }

    for (int i = 0; i <= M - 1; i++) {
        scanf("%d %d", &start, &end);
        if (merge(start, end)) {
            printf("%d", i + 1);
            return 0;
        }
    }

    printf("0");
    return 0;
}
