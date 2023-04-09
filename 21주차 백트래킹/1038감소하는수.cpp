#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

int N;
struct component {
    long int sum;
    int pre;
    int depth;

    component(long int _sum, int _pre, int _depth) {
        sum = _sum;
        pre = _pre;
        depth = _depth;
    }
    bool operator<(const component &b) const { return sum > b.sum; }
};
priority_queue<component> q;

void BFS() {
    for (int i = 0; i <= 9; i++) {
        q.push(component(i, i, 1));
    }
    while (!q.empty()) {
        component front = q.top();
        long int num = front.sum;
        int pre = front.pre;
        int depth = front.depth;
        // cout << num << ":" << pre << " ";

        q.pop();
        if (N == 0) {
            cout << num;
            return;
        }
        N--;

        // cout << num << " ";
        for (int i = pre + 1; i <= 9; i++) {
            // cout << num + pow(10, depth) * i << ":" << i << "/";

            q.push(component(num + pow(10, depth) * i, i, depth + 1));
        }
        cout << "\n ";
    }
}

int main() {
    cin >> N;
    if (N >= 1023) {
        cout << -1;
        return 0;
    }
    BFS();
}