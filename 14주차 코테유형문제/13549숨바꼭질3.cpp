/*

수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에
있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수
있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게
된다. 순간이동을 하는 경우에는 0초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른
시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
*/

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
struct node {
    int where;
    int depth;
    //생성자
    node() {}
    node(int _where, int _depth) {
        where = _where;
        depth = _depth;
    }

    bool operator<(const node &b) const { return depth > b.depth; }
};

priority_queue<node> pq;
bool visit[100005];

int main() {
    int n, k;

    cin >> n >> k;

    pq.push(node(n, 0));

    while (!pq.empty()) {
        int x = pq.top().where;
        int time = pq.top().depth;

        pq.pop();

        visit[x] = 1;
        // cout << x << " ";

        if (x == k) {
            cout << time;
            break;
        }

        if (x - 1 >= 0 && !visit[x - 1])
            pq.push(node(x - 1, time + 1));
        if (x + 1 <= 100000 && !visit[x + 1])
            pq.push(node(x + 1, time + 1));
        if (x * 2 <= 100000 && !visit[x * 2])
            pq.push(node(x * 2, time));
    }

    return 0;
}