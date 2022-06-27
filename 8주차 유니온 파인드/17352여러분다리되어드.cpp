/*

 백준 17352  문제
 여러분의 다리가 되어 드리겠습니다

*/

#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 300001
using namespace std;

int N;
int parent[MAX];

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

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // input
    cin >> N;
    int start, end;
    // 부모 노드 배열 초기화 ( 자기 자신 가르킴)
    for (int i = 0; i < MAX; i++)
        parent[i] = i;

    for (int i = 0; i < N - 2; i++) {
        cin >> start >> end;
        merge(start, end);
    }

    for (int i = 2; i <= N; i++) {

        if (!isUnion(1, i)) {
            cout << 1 << " " << i;

            return 0;
        }
    }
}
