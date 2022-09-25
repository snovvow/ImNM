/*

첫 번째 줄에는 회전 초밥 벨트에 놓인 접시의 수 N, 초밥의 가짓수 d, 연속해서 먹는
접시의 수 k, 쿠폰 번호 c가 각각 하나의 빈 칸을 사이에 두고 주어진다. 단, 2 ≤ N ≤
30,000, 2 ≤ d ≤ 3,000, 2 ≤ k ≤ 3,000 (k ≤ N), 1 ≤ c ≤ d이다. 두 번째 줄부터
N개의 줄에는 벨트의 한 위치부터 시작하여 회전 방향을 따라갈 때 초밥의 종류를
나타내는 1 이상 d 이하의 정수가 각 줄마다 하나씩 주어진다.

*/

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
int N, d, k, c;
int ans;
int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> d >> k >> c;

    vector<int> v;
    int chobab;
    for (int i = 0; i < N; i++) {
        cin >> chobab;
        v.push_back(chobab);
    }

    map<int, int> m;
    int couCount = 0;
    // k 단위로 슬라이싱 하면서 set 에서 넣거나 빼줌. 근데 쿠폰은 무조건 넣고
    // 시작함.
    // set 에 들어가있는 요소의 갯수의 최댓값만 계산해주면됨.
    if (N < k) {
        // 벡터 길이가 짧을때
    }
    int left = 0;
    int right = 0;
    // 초기 세팅
    for (; right < k && right < v.size(); right++) {
        m[v[right]]++;
    }
    // cout << 3 << "번째 ";
    // for (auto ccc : m) {
    //     cout << ccc.first << "," << ccc.second << " ";
    // }

    // cout << endl;
    int cnt = m.size();
    // cout << cnt;

    if (m.find(c) == m.end()) {
        ans = max(cnt + 1, ans);
    } else {
        ans = max(cnt, ans);
    }

    while (left < v.size()) {
        m[v[left]]--;
        // cout << m[v[i - k]];
        if (m[v[left]] == 0)
            m.erase(v[left]);
        m[v[right % N]]++;

        cnt = m.size();
        // m[c] 로접근하면 초기화가됨 ㅋㅋ
        if (m.find(c) == m.end()) {
            ans = max(cnt + 1, ans);
        } else {
            ans = max(cnt, ans);
        }
        right++;
        left++;
        // cout << i << "번째 ";
        // for (auto ccc : m) {
        //     cout << ccc.first << " ";
        // }
        // cout << endl;
    }

    cout << ans;
}