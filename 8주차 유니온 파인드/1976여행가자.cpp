/*

 백준 1976  여행가자
 여러분의 다리가 되어 드리겠습니다

*/

#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 201
using namespace std;

int N;
int M;
int parent[MAX];
int travle[1000];

int find(int x) {
    if (parent[x] == x)
        return x;
    // 뭐임 이건
    // find(parent[x]) 한값을 그대로 리턴..
    // 직선으로 만드는 느낌..?
    // 편중 현상... 때문에 찾을때마다 루트노드 하나로 모으게끔??
    // https://ip99202.github.io/posts/%EC%9C%A0%EB%8B%88%EC%98%A8-%ED%8C%8C%EC%9D%B8%EB%93%9C(Union-Find)/
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

// bool travleCheck(int index) {
//     if (index <= M - 1) {
//         return true;
//     }
//     if (isUnion(travle[index], travle[index + 1]))
//         return travleCheck(index + 1);
//     else
//         return false;
// }

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    scanf("%d", &M);

    int start, end, valid;

    for (int i = 0; i < MAX; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= N; k++) {
            scanf("%d", &valid);
            if (valid) {
                merge(i, k);
            }
        }
    }

    for (int i = 1; i <= M; i++) {
        scanf("%d", &travle[i]);
    }
    bool check = true;
    for (int i = 1; i <= M - 1; i++) {
        if (!isUnion(travle[i], travle[i + 1]))
            check = false;
    }

    if (check) {
        printf("YES");
    } else {
        printf("NO");
    }
}
