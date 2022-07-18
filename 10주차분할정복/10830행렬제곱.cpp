/*

 백준 1074
 z 분할정복
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int n;
long long B;
long long matrix[5][5];
long long result[5][5];
long long temp[5][5];

void calculateMatrix(long long x[5][5], long long y[5][5]) {
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            // A 에서  -- ㅣㅣ
            temp[i][k] = 0;
            for (int j = 0; j < n; j++) {
                temp[i][k] += x[i][j] * y[j][k];
            }
            temp[i][k] %= 1000;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            // A 에서  -- ㅣㅣ
            x[i][k] = temp[i][k];
        }
    }
}

void divide(long long howMany) {
    if (howMany <= 0) {
        // calculateMatrix(matrix, matrix);
        return;
    }

    if (howMany % 2 == 1) {
        calculateMatrix(result, matrix);
    }
    calculateMatrix(matrix, matrix);

    divide(howMany / 2);
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> B;
    // cout << B << endl;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            cin >> matrix[i][k];
        }
        result[i][i] = 1;
    }
    divide(B);

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            // A 에서  -- ㅣㅣ
            cout << result[i][k] << " ";
        }
        cout << "\n";
    }
}
