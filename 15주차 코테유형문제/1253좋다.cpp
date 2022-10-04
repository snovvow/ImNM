/*
N개의 수 중에서 어떤 수가 다른 수 두 개의 합으로 나타낼 수 있다면 그 수를
“좋다(GOOD)”고 한다.

N개의 수가 주어지면 그 중에서 좋은 수의 개수는 몇 개인지 출력하라.

수의 위치가 다르면 값이 같아도 다른 수이다.

입력
첫째 줄에는 수의 개수 N(1 ≤ N ≤ 2,000), 두 번째 줄에는 i번째 수를 나타내는 Ai가
N개 주어진다. (|Ai| ≤ 1,000,000,000, Ai는 정수)

출력
좋은 수의 개수를 첫 번째 줄에 출력한다.

3,4,5,6,7,8,9,10은 좋다.

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl '\n'

int N;
vector<int> map;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int input;

    for (int i = 0; i < N; i++) {
        cin >> input;
        map.push_back(input);
    }
    sort(map.begin(), map.end());
    int answer = 0;
    for (int i = 0; i < N; i++) {
        int left = 0;
        int right = N - 1;
        while (left < right) {
            int twoSum = map[left] + map[right];
            if (left == i) {
                left++;
                continue;
            }
            if (right == i) {
                right--;
                continue;
            }

            if (twoSum == map[i]) {
                // cout << left << " " << right << endl;
                answer++;
                break;
            }

            if (twoSum > map[i]) {

                right--;
            } else if (twoSum < map[i]) {
                left++;
            }
        }
    }

    cout << answer;
}
