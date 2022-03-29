/*

 백준 14469 문제
 소가 길을 건너간 이유
*/

#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

struct cow {
    int enter;
    int time;

    //생성자
    cow(int Center, int Ctime) {
        enter = Center;
        time = Ctime;
    }

    bool operator<(const cow &a) const {
        if (enter == a.enter)
            return time < a.time;
        else
            return enter < a.enter;
    }
};

int main(int argc, char *argv[]) {
    int n;
    vector<cow> v;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int enter, time;
        scanf("%d %d", &enter, &time);
        v.push_back(cow(enter, time));
    }

    sort(v.begin(), v.end());

    int result = 0;

    for (int i = 0; i < n; i++) {
        if (result < v[i].enter) {
            result = v[i].time + v[i].enter;
        } else {
            result += v[i].time;
        }
    }

    printf("%d", result);
}