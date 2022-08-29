/*

 백준 1074
 z 분할정복
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

int N, P, E;
struct Person {
    int min;
    int max;
    int idx;
    int give = 0;
    bool visitCheck = false;

    // //생성자
    Person() {}

    Person(int _idx, int _start, int _end) {
        idx = _idx;
        min = _start;
        max = _end;
    }
};
// 요래 생성해버리면 디폴트 생성자가 필요
Person p[1000000];
// 백터쓰면 디폴트 필요없음
vector<Person> answer;
bool isAnswer = false;

void dfs(int idx, int cnt) {
    if (isAnswer)
        return;
    if (cnt == P) {
        int min = 0, max = 0;
        for (int i = 0; i < answer.size(); i++) {
            min += answer[i].min;
            max += answer[i].max;
        }
        if (min <= E && E <= max) {
            for (int i = 0; i < answer.size(); i++) {
                answer[i].give = answer[i].min;
                p[answer[i].idx].give = answer[i].give;
            }
            isAnswer = true;

            int leftLoverDuck = E - min;
            for (int i = 0; i < leftLoverDuck; i++) {
                bool sumCheck = false;
                for (int k = 0; k < answer.size(); k++) {
                    int temp = answer[k].give + 1;
                    if (!sumCheck && (temp <= answer[k].max)) {
                        answer[k].give += 1;
                        p[answer[k].idx].give = answer[k].give;
                        sumCheck = true;
                    }
                }
            }
            return;
        }
    }
    for (int i = idx; i < N; i++) {
        if (p[i].visitCheck == true)
            continue;
        p[i].visitCheck = true;
        answer.push_back(p[i]);
        dfs(i, cnt + 1);
        answer.pop_back();
        p[i].visitCheck = false;
    }
}

int main(int argc, char *argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> P >> E;
    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        p[i] = Person(i, x, y);
    }
    dfs(0, 0);
    if (isAnswer) {
        for (int i = 0; i < N; i++) {
            cout << p[i].give << " ";
        }
    } else {
        cout << "-1";
    }
}
