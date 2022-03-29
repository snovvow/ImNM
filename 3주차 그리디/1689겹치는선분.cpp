/*

 백준 1946 문제
 소가 길을 건너간 이유
*/

#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

struct line {
    int dot;
    int state;

    //생성자
    line(int Cdot, int Cstate) {
        dot = Cdot;
        state = Cstate;
    }

    bool operator<(const line &a) const {
        if (dot == a.dot)
            return state < a.state;
        else
            return dot < a.dot;
    }
};

int main(int argc, char *argv[]) {

    // test case
    int n;
    vector<line> v;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int start, end;

        scanf("%d %d", &start, &end);
        v.push_back(line(start, 1));
        v.push_back(line(end, -1));
    }

    sort(v.begin(), v.end());

    int maxCnt = 1;

    int cnt = 1;

    for (int i = 1; i <= 2 * (n - 1); i++) {
        cnt += v[i].state;
        maxCnt = max(maxCnt, cnt);
    }

    printf("%d\n", maxCnt);
}