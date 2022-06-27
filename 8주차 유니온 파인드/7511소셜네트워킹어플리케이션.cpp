/*

 백준 7511 소셜네트워킹 서비스

*/

#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

int T;
int UsersCount;
int friendShipCount;
int shouldCheckFriendShipCount;
int parent[MAX];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    // 부모노드를 첫번째 놈으로 합쳐버림
    parent[y] = x;
}

bool isUnion(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return true;
    return false;
}

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    int loopCount = 1;
    while (loopCount <= T) {
        scanf("%d", &UsersCount);
        for (int i = 0; i < UsersCount; i++) {
            parent[i] = i;
        }

        scanf("%d", &friendShipCount);
        int a, b;
        for (int i = 0; i < friendShipCount; i++) {
            scanf("%d %d", &a, &b);
            merge(a, b);
        }

        int u, v;
        printf("Scenario %d:\n", loopCount);
        scanf("%d", &shouldCheckFriendShipCount);

        for (int i = 0; i < shouldCheckFriendShipCount; i++) {
            scanf("%d %d", &u, &v);
            printf("%d\n", isUnion(u, v));
        }
        printf("\n");

        loopCount++;
    }
}
