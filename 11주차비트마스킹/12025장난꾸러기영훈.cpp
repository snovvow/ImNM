/*

 백준 1074
 z 분할정복
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

string input;
uint64_t k, n = 1;

int main(int argc, char *argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> input >> k;

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '1' || input[i] == '6') {
            input[i] = '1';
            n *= 2;
        }
        if (input[i] == '2' || input[i] == '7') {
            input[i] = '2';
            n *= 2;
        }
    }
    //  n이 가능한 경우의 수가 주어진 k 보다 적어뻐리면...
    if (k > n) {
        cout << "-1";
        return 0;
    }
    k -= 1;
    //각 자리 수가 1,6 인지 2,7 인지 구별하는건 그냥 값비교로 해주고
    // 나머지 연산을 통해서 비트가 1인걸 알면은 뒤에서 몇번째 자리수가 더큰수로
    // 바뀌고 말지를 알 수있다.
    for (int i = input.size() - 1; i >= 0; i--) {
        switch (input[i]) {
        case '1':
            if (k % 2)
                input[i] = '6';
            k /= 2;
            break;
        case '2':
            if (k % 2)
                input[i] = '7';
            k /= 2;
            break;
        default:
            break;
        }
    }
    cout << input;
}
