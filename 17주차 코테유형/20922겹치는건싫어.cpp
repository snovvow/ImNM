

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int N, K;

int map[200001];
int countValue[100001];

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;

    int input;

    for (int i = 0; i < N; i++) {
        cin >> input;
        map[i] = input;
    }
    int start = 0;
    int end = 0;
    int result = 0;

    while (start < N) {
        int value = map[start];
        if (countValue[value] != K) {
            countValue[value]++;
            start++;
        } else {
            countValue[map[end]]--;
            end++;
        }
        result = max(result, start - end);
    }
    cout << result << "\n";
    return 0;
}
