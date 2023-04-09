#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <unordered_set>
#include <vector>
#define INTMAX 2147483647

using namespace std;

unordered_set<string> memo;

vector<string> tokenized(string s) {
    vector<string> result;
    stringstream ss(s);

    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        result.push_back(substr);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;

    // 메모장
    string input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        memo.insert(input);
    }
    for (int i = 0; i < M; i++) {
        cin >> input;
        vector<string> keywords = tokenized(input);
        for (int k = 0; k < keywords.size(); k++) {
            string Key = keywords[k];
            if (memo.find(Key) != memo.end()) {
                memo.erase(memo.find(Key));
            }
        }
        cout << memo.size() << "\n";
    }
    return 0;
}