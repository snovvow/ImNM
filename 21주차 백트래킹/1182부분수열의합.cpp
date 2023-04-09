#include <algorithm>
#include <iostream>

using namespace std;

int map[21];
int cnt;
int N, S;

void back(int cur, int result) {
    if (cur == N) {
        if (result == S) {
            cnt++;
        }
        return;
    }
    back(cur + 1, result);
    back(cur + 1, result + map[cur]);
}

int main() {
    cin >> N >> S;
    for (int n = 0; n < N; n++) {
        cin >> map[n];
    }

    back(0, 0);

    if (S == 0)
        cnt--;
    cout << cnt;
}