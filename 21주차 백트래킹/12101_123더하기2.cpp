#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> v;
bool ans;
void back(int sum) {

    if (sum == N) {
        // cout << sum;
        K--;
        if (K == 0) {
            // 정답일 때 백트래킹 시작해야함.
            cout << v[0];
            for (int i = 1; i < v.size(); i++) {
                cout << "+" << v[i];
            }
            ans = true;
            return;
        }
        return;
    }
    if (sum > N)
        return;
    v.push_back(1);
    back(sum + 1);
    v.pop_back();
    v.push_back(2);
    back(sum + 2);
    v.pop_back();
    v.push_back(3);
    back(sum + 3);
    v.pop_back();
}

int main() {
    cin >> N >> K;
    for (int i = 1; i <= 3; i++) {
        // 1 , 2 ,3 순으로 백트래킹 시작
        v.push_back(i);
        back(i);
        v.pop_back();
    }

    if (!ans) {
        cout << "-1";
    }
}