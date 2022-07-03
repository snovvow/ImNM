#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int answer;
string input;
int dp[50][50];
int solve(int left, int right) {
    if (dp[left][right] != -1)
        return dp[left][right];
    if (left >= right)
        return 0;
    dp[left][right] = min(
        {// 왼쪽에있는 놈을 삭제또는 왼쪽놈을 오른쪽에 붙여줌 ( 아무튼 왼쪽놈을
         // 처리했다 ! )
         solve(left + 1, right) + 1,
         // 오른쪽에 있는 놈을 삭제 또는 오른쪽 놈을 왼쪽에 붙여줌 ( 아무튼
         // 오른쪽놈을 처리했다 !)
         solve(left, right - 1) + 1,
         // 3번 서로 교환하는데 같아 땡큐하고 0 아님 1
         solve(left + 1, right - 1) + (input[left] == input[right] ? 0 : 1)});

    // 메모제이션 리턴
    return dp[left][right];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> input;

    // 4번조건을 안쓰고 , 123번만 이용
    memset(dp, -1, sizeof(dp));

    answer = solve(0, input.length() - 1);

    for (int i = 0; i < input.length() - 1; i++) {
        for (int j = i + 1; j < input.length(); j++) {
            memset(dp, -1, sizeof(dp));
            // 4번 로직을 그냥 모두다 적용해버림
            // 4번을 맨처음에 적용안하면 123번 두번씩 쓴 결과임
            swap(input[i], input[j]);
            answer = min(answer, solve(0, input.length() - 1) + 1);
            // 다시 되돌리기
            swap(input[i], input[j]);
        }
    }

    cout << answer;

    return 0;
}