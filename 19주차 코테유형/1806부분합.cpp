#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define INTMAX 2147483647

using namespace std;

int arr[100010];

int main() {
    int N, S;
    cin >> N >> S;

    int l = 0, sum = 0;
    int answer = 100001;
    for (int r = 0; r < N; ++r) {
        cin >> arr[r];
        sum += arr[r];

        while (sum >= S && l < N) {
            answer = min(answer, (r - l) + 1);
            sum -= arr[l];
            l++;
        }
    }

    if (answer == 100001)
        cout << 0;
    else
        cout << answer;

    return 0;
}