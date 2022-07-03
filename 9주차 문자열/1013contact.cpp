/*

 백준 1013
 contact
 “무한히 넓은 저 우주에 인류만이 홀로 존재한다면, 그건 정말 슬픈 일이 아닐까요”
*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int dfa[2][9] = {{1, -1, 1, 4, 5, 5, 1, 8, 5}, {3, 2, 3, -1, -1, 6, 7, 7, 0}};
int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T > 0) {
        string inputString;
        cin >> inputString;
        int stringToInt = inputString[0] - '0';
        int next = dfa[stringToInt][0];

        for (int i = 1; i < inputString.size(); i++) {
            stringToInt = inputString[i] - '0';
            next = dfa[stringToInt][next];
            if (next == -1) {
                break;
            }
        }
        // cout << next;

        if (next == 0 || next == 2 || next == 6 || next == 7) {
            cout << "YES"
                 << "\n";
        } else {
            cout << "NO"
                 << "\n";
        }

        T--;
    }
}
