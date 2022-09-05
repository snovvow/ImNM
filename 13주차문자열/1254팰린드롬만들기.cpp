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

#define endl "\n"
using namespace std;
string s;

bool isPalindrom(string inp) {
    string temp = inp;
    reverse(inp.begin(), inp.end());
    if (temp == inp)
        return true;
    return false;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    int ans = 1e9;
    if (isPalindrom(s)) {
        cout << s.length();
        return 0;
    }

    for (int i = 0; i < s.length(); i++) {
        string temp = s.substr(i, s.length());
        if (isPalindrom(temp)) {
            int len = s.length() - temp.length();
            ans = min(ans, len);
        }
    }
    if (ans == 1e9)
        cout << s.length() * 2;
    cout << ans + s.length();
}