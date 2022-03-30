/*

 백준 2812 문제
 크게만들기
*/

#include <algorithm>
#include <deque>
#include <stdio.h>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {

    // test case
    int n, k;
    deque<int> dq;

    scanf("%d %d", &n, &k);
    int saveNum = 0;
    int num;
    scanf("%1d", &num);
    dq.push_back(num);

    for (int i = 1; i < n; i++) {
        scanf("%1d", &num);
        // printf("dq back %d   \n", dq.back());

        while (k && !dq.empty() && dq.back() < num) {
            // printf("%d   ", i);
            dq.pop_back();
            k--;
        }
        dq.push_back(num);
    }
    // for (int i = 1; i <= n; i++) {
    //         int num;
    //         scanf("%1d", &num);
    //         dq.push_back(num);
    //     }

    // 큰수부터 차근차근 선택을 하는건 어떨까,,,,.?
    // 지우기말고 뽑기로?

    for (int i = 0; i < dq.size() - k; i++) {
        printf("%d", dq[i]);
    }
}