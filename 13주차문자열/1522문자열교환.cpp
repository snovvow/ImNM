/*

 26개중 5개를 뺀 21개의 순수 영어 중에
 모든 조합돌면서 | or 연산 때려서
 50 ,49 .. 30 ~ 1 까지 모든 조합수중에서 or 연산시에
 K - 5 한값과 작거나 같은 경우를 최대의 max로 설정함.

*/

#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int solve(string &s, int x, int len) {
    int ret = 0;
    for (int i = x; i < x + len; i++)
        // 원형 슬라이드
        if (s[(i + 1) % s.length()] == 'b')
            ret++;
    return ret;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;

    cin >> s;
    int cnt = 0, ans = (int)1e9;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == 'a')
            cnt++;

    // cout << cnt;
    for (int i = 0; i < s.length(); i++)
        ans = min(ans, solve(s, i, cnt));
    cout << ans;
    return 0;
}