/*

 백준 15486  문제
 퇴사 2
*/

#include <algorithm>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;
int L;
int D;
// bool visitCheck[12];
int result = 0;
int distanceSave[10001];

struct load {
    int start;
    int end;
    int length;

    //생성자
    load(int _start, int _end, int _length) {
        start = _start;
        end = _end;
        length = _length;
    }

    // 비교 구문이 반대로 감? 오름
    // bool operator<(const load &b) const { return length > b.length; }
};

vector<load> v[10001];

void ds(int num) {
    if (num == D + 1)
        return;
    int saveSmall = 99999999;
    int originalDiastance = distanceSave[num - 1] + 1;
    if (v[num].size() == 0) {
        distanceSave[num] = originalDiastance;

    } else {
        for (int i = 0; i < v[num].size(); i++) {
            saveSmall = min(originalDiastance,
                            min(saveSmall, distanceSave[v[num][i].start] +
                                               v[num][i].length));
        }

        distanceSave[num] = saveSmall;
    }

    ds(num + 1);
}

int main(int argc, char *argv[]) {

    // input
    scanf("%d %d", &L, &D);

    for (int i = 0; i < L; i++) {
        int start, end, length;
        scanf("%d %d %d", &start, &end, &length);
        if (end > D)
            continue;
        v[end].push_back(load(start, end, length));
    }
    ds(1);

    printf("%d", distanceSave[D]);
}