/*

 백준 2437 문제
 저울
*/

#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {

    // test case
    int n;
    scanf("%d", &n);

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int input;
        scanf("%d", &input);
        v.push_back(input);
    }
    sort(v.begin(), v.end());

    int sum = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {

        // 하나 뺀것보다 작으면 그게 정답
        if (sum < v[i] - 1) {
            flag = true;
            printf("%d", sum + 1);
            break;
        }
        sum += v[i];
    }

    if (!flag) {
        printf("%d", sum + 1);
    }
}