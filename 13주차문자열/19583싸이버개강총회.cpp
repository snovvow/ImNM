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
string S, E, Q;
int start, endTime, quit;
map<string, int> save;

int transformToMin(string input) {
    stringstream sstream(input);
    string word;
    int sum = 0;
    int loopCnt = 1;
    while (getline(sstream, word, ':')) {
        sum += stoi(word) * (1 + 59 * loopCnt);
        loopCnt--;
    }
    return sum;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> S >> E >> Q;
    string time, name;
    start = transformToMin(S);
    endTime = transformToMin(E);
    quit = transformToMin(Q);
    int ans = 0;

    while (!std::cin.eof()) {
        cin >> time >> name;
        int ToMinTime = transformToMin(time);
        if (ToMinTime <= start) {
            save[name] = 1;
        } else if (ToMinTime < endTime) {
            // do noting
        } else if (ToMinTime <= quit) {
            if (save[name] == 1) {
                save[name] = 0;
                ans++;
                // cout << name;
            }
        }
    }
    cout << ans;
}