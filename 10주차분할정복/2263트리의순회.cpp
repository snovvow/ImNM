/*

 백준 1074
 z 분할정복
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int Index[100001];
int arrInOrder[100001];
int arrPostOrder[100001];

void preOrder(int inOrderLeft, int inOrderRight, int postOrderLeft,
              int postOrderRight) {

    if (inOrderLeft > inOrderRight || postOrderLeft > postOrderRight)
        return;

    int valueOfLastIndex = arrPostOrder[postOrderRight];

    int inOrderRootIndex = Index[valueOfLastIndex];
    int leftSize = inOrderRootIndex - inOrderLeft;

    cout << valueOfLastIndex << ' '; // root 값 출력
    // cout << inOrderRootIndex << "asdfasdf";
    //중위 정보
    // [왼쪽] / root / [오른쪽]
    // 후위 정보
    // [왼쪽]  /  [오른쪽]   / root
    // 주의 미들값으로 바로 집어넣으면 따로따로 놀아서 연동이안됨

    // 왼쪽으로 이동
    preOrder(inOrderLeft, inOrderRootIndex - 1, postOrderLeft,
             postOrderLeft + leftSize - 1);
    // 오른쪽으로 이동
    preOrder(inOrderRootIndex + 1, inOrderRight, postOrderLeft + leftSize,
             postOrderRight - 1);

    // getPreOrder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
    // getPreOrder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    // s n k r1 r2 c1 c2
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arrInOrder[i];
        Index[arrInOrder[i]] = i; // inorder 요소들의 Index 정보 저장
    }
    for (int i = 1; i <= N; i++) {
        cin >> arrPostOrder[i];
    }

    preOrder(1, N, 1, N);

    // for (int i = R1; i <= R2; i++) {
    //     for (int k = C1; k <= C2; k++) {
    //         cout << printByrAndc(i, k, len);
    //     }
    //     cout << endl;
    // }
}
