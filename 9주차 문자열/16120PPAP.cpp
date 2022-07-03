#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
string input;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int pCounter = 0;

    cin >> input;
    bool possiblePPAP = false;
    int ACounter = 0;
    if (input.size() == 1 && input[0] == 'P') {
        cout << "PPAP";
        return 0;
    }
    for (int i = 0; i < input.size(); i++) {

        if (input[i] == 'P')
            pCounter++;

        // cout << input[i] << pCounter << possiblePPAP << " ";

        if (possiblePPAP) {
            possiblePPAP = false;
            if (input[i] == 'P') {
                pCounter = pCounter - 2;
            }
            if (input[i] == 'A') {
                possiblePPAP = true;
                break;
            }
        }

        if (input[i] == 'A' && pCounter >= 2) {
            possiblePPAP = true;
            ACounter++;
        } else if (input[i] == 'A') {
            possiblePPAP = true;
            break;
        }
    }

    if (possiblePPAP || ACounter == 0) {
        cout << "NP";
        return 0;
    }

    cout << "PPAP";
}