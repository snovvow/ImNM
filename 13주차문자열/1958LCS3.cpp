#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int LCS[101][101][101];

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string A, B, C;
    // input
    cin >> A >> B >> C;

    int ans = -1;

    for (int i = 1; i <= A.length(); i++) {
        for (int j = 1; j <= B.length(); j++) {
            for (int k = 1; k <= C.length(); k++) {
                if (A[i - 1] == B[j - 1] && B[j - 1] == C[k - 1]) {
                    LCS[i][j][k] = LCS[i - 1][j - 1][k - 1] + 1;
                } else {
                    LCS[i][j][k] = max(
                        {LCS[i][j - 1][k], LCS[i - 1][j][k], LCS[i][j][k - 1]});
                }
                if (ans < LCS[i][j][k]) {
                    ans = LCS[i][j][k];
                }
            }
        }
    }

    cout << ans;
}
