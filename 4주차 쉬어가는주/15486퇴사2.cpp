/*

 백준 15486  문제
 퇴사 2
*/

#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

struct work {
    int day;
    int money;

    //생성자
    work(int _day, int _money) {
        day = _day;
        money = _money;
    }

    // bool operator<(const work &a) const { return day < a.day; }
};

int dp[1500001];

int main(int argc, char *argv[]) {

    // test case
    int n;
    vector<work> v;
    int day, money;
    // trash input
    v.push_back(work(0, 0));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &day, &money);
        v.push_back(work(day, money));
    }
    int maxnum = 0;
    for (int i = 1; i <= v.size(); i++) {

        // i 가 뒤에서 부터 가는 날짜임
        // 디피를 갱신할수 있는 경우임
        int newDay = v[i].day + i;
        maxnum = max(maxnum, dp[i]);

        if (newDay <= n + 1) {

            // printf("%d %d %d\n", v[i].money, v[i].day, dp[i]);
            dp[newDay] = max(v[i].money + maxnum, dp[newDay]);
        }
        // dp[i] = max(dp[i - 1], dp[i]);
    }

    // for (int i = 1; i <= v.size(); i++) {
    //     printf("%d\n", dp[i]);
    // }

    printf("%d\n", maxnum);
}