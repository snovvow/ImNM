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
int N, M;

bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
    if (a.second == b.second) {
        if (a.first.length() == b.first.length())
            return a.first < b.first;
        return a.first.length() > b.first.length();
    }
    return a.second > b.second;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    map<string, int> m;

    string input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        if (input.length() >= M) {
            m[input]++;
            // cout << input;
        }
    }

    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    for (auto node : v) {
        cout << node.first << "\n";
    }
}