#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int N;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    cout << N * (N - 1) / 2 << endl;
    int num = 1;
    for (int i = 0; i < N; i++) {
        cout << num << " ";
        num *= 2;
    }

    cout << endl << N - 1 << endl;
    num = 1;
    for (int i = 0; i < N; i++) {
        cout << num << " ";
        num += 1;
    }
}
