#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define INTMAX 2147483647
#define INTMIN -2147483648

using namespace std;

int T;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    // game

    for (int t = 1; t <= T; t++) {
        string W;
        int K;
        int count[26];

        cin >> W >> K;
        int WLength = W.length();
        for (int l = 0; l < WLength; l++) {
            count[W[l] - 'a']++;
        }

        int answer3 = INTMAX;
        int answer4 = INTMIN;
        for (int i = 0; i < WLength; ++i) {
            if (count[W[i] - 'a'] < K)
                continue;

            int cnt = 0;
            for (int j = i; j < WLength; ++j) {
                if (W[i] == W[j])
                    ++cnt;

                if (cnt == K) { // 카운트 수가 K 와 같을 때 길이 업데이트
                    answer3 = min(answer3, j - i + 1);
                    answer4 = max(answer4, j - i + 1);
                    break;
                }
            }
        }

        if (answer3 == INTMAX || answer4 == INTMIN)
            cout << -1 << "\n";
        else
            cout << answer3 << " " << answer4 << "\n";
    }
    return 0;
}