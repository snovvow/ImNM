#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define INTMAX 2147483647
#define INTMIN -2147483648

using namespace std;

int N;
int map[101];
int visited[101];
vector<int> v;

void dfs(int target, int current) {
    if (visited[current] == 1) {
        if (target == current) {
            v.push_back(current);
        }
        return;
    } else {
        visited[current] = 1;
        dfs(target, map[current]);
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    // game

    for (int t = 1; t <= N; t++) {
        cin >> map[t];
    }

    for (int t = 1; t <= N; t++) {
        for (int i = 0; i <= N; i++) {
            visited[i] = 0;
        }
        dfs(t, t);
    }

    cout << v.size() << "\n";
    for (auto i : v) {
        cout << i << "\n";
    }

    return 0;
}