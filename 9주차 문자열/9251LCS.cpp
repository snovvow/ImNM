/*

 백준 9251
 LCS 최장공통부분 수열
*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int LCS[1001][1001];
int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string A;
    string B;

    // input
    cin >> A;
    cin >> B;
    int ans = -1;
    for (int i = 1; i <= A.length(); i++) {
        for (int j = 1; j <= B.length(); j++) {
            int maxLCS = 0;
            if (A[i - 1] == B[j - 1]) {

                LCS[i][j] = LCS[i - 1][j - 1] + 1;

            } else {
                LCS[i][j] = max(LCS[i][j - 1], LCS[i - 1][j]);
            }

            if (ans < LCS[i][j]) {
                ans = LCS[i][j];
            }
        }
    }

    cout << ans;
}
