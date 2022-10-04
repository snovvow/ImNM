#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define endl '\n'
#define maxR 7
#define maxC 8
int H, W;
int T;

string temp = "";
int map[500];

void abGame(string s, string t) {
    //
    if (s == t) { // 3
        cout << 1 << "\n";
        exit(0);
    }
    if (s.size() >= t.size())
        return;
    if (t[t.size() - 1] == 'A') {
        temp = t;
        temp.erase(temp.size() - 1);
        abGame(s, temp);
    }
    if (t[0] == 'B') {
        temp = t;
        temp.erase(0, 1);
        reverse(temp.begin(), temp.end());
        abGame(s, temp);
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int answer = 0;
    string s, t;
    cin >> s >> t;
    abGame(s, t);
    cout << 0 << "\n";
}
