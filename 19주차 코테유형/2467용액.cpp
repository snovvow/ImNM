#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define INTMAX 2147483647

using namespace std;

int N;
int liquid[100001];

int main(int argc, char *argv[]) {

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> liquid[i];
    }

    int l = 0, r = N - 1;
    int a, b;
    int sum = INTMAX;
    while (l < r) {
        int tmpSum = liquid[l] + liquid[r];

        if (abs(sum) > abs(tmpSum)) {
            sum = tmpSum;
            a = liquid[l];
            b = liquid[r];
        }
        if (tmpSum == 0)
            break;
        if (tmpSum > 0) {
            r--;
        } else {
            l++;
        }
    }
    cout << a << " " << b << "\n";
}