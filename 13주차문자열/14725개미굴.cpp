
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Node {
    map<string, Node> child;

    void insert(vector<string> v, int idx) {
        if (idx == v.size())
            return;

        if (!child.count(v[idx]))
            child[v[idx]] = Node();

        child[v[idx]].insert(v, idx + 1);
    }

    void print(int depth = 0) {
        // 어느 깊이에 있는 모든 노드들을 가져옵니다.
        for (auto node : child) {
            for (int i = 0; i < depth; i++) {
                cout << "--";
            }
            cout << node.first << endl;

            // DFS이므로 깊이 순으로 타고 들어갑니다.
            node.second.print(depth + 1);
        }
    }
};

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Node root;
    int N;
    cin >> N;
    int K;
    for (int i = 0; i < N; i++) {
        cin >> K;
        int input;
        vector<string> v(K);

        for (int j = 0; j < K; j++) {
            cin >> v[j];
        }
        root.insert(v, 0);
    }

    root.print();
}
