#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
using namespace std;
string input;
string password;
int divideNum = 900528;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> input;
    cin >> password;
    map<char, int> m;

    for (int i = 0; i < input.length(); i++) {
        m.insert(make_pair(input[i], i + 1));
    }

    int sum = 0;
    int inputLength = input.length();
    int powCalculated = 1;
    for (int i = password.length() - 1; i >= 0; i--) {
        char getOneByOne = password[i];
        int findOrder = m.find(getOneByOne)->second;
        sum = (sum + findOrder * powCalculated) % divideNum;
        powCalculated = powCalculated * inputLength % divideNum;
    }
    // sum = (sum + m.find(password[password.length() - 1])->second) %
    // divideNum;

    cout << sum;
}
