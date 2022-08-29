/*

 26개중 5개를 뺀 21개의 순수 영어 중에
 모든 조합돌면서 | or 연산 때려서
 50 ,49 .. 30 ~ 1 까지 모든 조합수중에서 or 연산시에
 K - 5 한값과 작거나 같은 경우를 최대의 max로 설정함.

*/

#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#define endl "\n"
using namespace std;
int N, K, Answer;
bool alphabet[26];
string antic = "antic";
vector<string> V;
void dfs(int idx, int cnt) {
    if (cnt == K) {
        int canRead = 0;

        for (int i = 0; i < V.size(); i++) {
            string str = V[i];
            bool read = true;
            for (int j = 0; j < str.length(); j++) {
                if (alphabet[str[j] - 'a'] == false) {
                    read = false;
                    break;
                }
            }
            if (read)
                canRead++;
        }

        Answer = max(Answer, canRead);
    }

    for (int i = idx; i < 26; i++) {
        if (alphabet[i] == true)
            continue;
        alphabet[i] = true;
        dfs(i, cnt + 1);
        alphabet[i] = false;
    }
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    if (K < 5) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        V.push_back(tmp);
    }
    for (int k = 0; k < antic.length(); k++)
        alphabet[antic[k] - 'a'] = true;
    K = K - 5;
    dfs(0, 0);
    cout << Answer << endl;
}

// #include <algorithm>
// #include <cmath>
// #include <iostream>
// #include <vector>
// using namespace std;

// string input;
// int N, K;
// uint32_t bits[50];
// vector<uint32_t> dfsBits;
// vector<uint32_t> v;
// bool bitsCheck[50];
// string antic = "antic";
// int answer = 0;
// bool answerCheck = false;

// int bitCount(uint32_t s) {
//     int sz = 0;
//     while (s) {
//         sz += (s & 1);
//         s >>= 1;
//     }
//     return sz;
// }

// void dfs(int idx, int cnt, int maxCnt) {
//     if (cnt == maxCnt) {
//         uint32_t checkSum = 0;
//         for (int i = 0; i < v.size(); i++) {
//             checkSum |= v[i];
//         }
//         if (bitCount(checkSum) <= K) {
//             answer = maxCnt;
//             return;
//         };
//     }
//     for (int i = idx; i < N; i++) {
//         if (bitsCheck[i] == true)
//             continue;
//         bitsCheck[i] = true;
//         v.push_back(bits[i]);
//         dfs(i, cnt + 1, maxCnt);
//         v.pop_back();
//         bitsCheck[i] = false;
//     }
// }

// int main(int argc, char *argv[]) {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     cin >> N >> K;
//     if (K < 5) {
//         cout << 0;
//         return 0;
//     }
//     for (int i = 0; i < N; i++) {
//         cin >> input;
//         for (int k = 0; k < input.length(); k++) {
//             bits[i] |= (1 << (input[k] - 97));
//         }
//         // 그냥 여기서 조합에 들어갈 필요도 없는 놈들 제거
//         if (bitCount(bits[i]) <= K) {
//             bool flag = true;
//             for (int j = 0; j < dfsBits.size(); j++) {
//                 if (dfsBits[j] == bits[i])
//                     flag = false;
//             }
//             if (flag) {
//                 dfsBits.push_back(bits[i]);
//             }
//         }
//     }
//     cout << dfsBits.size();

//     for (int i = dfsBits.size(); i >= 1; i--) {
//         if (answer)
//             continue;
//         dfs(0, 0, i);
//     }
//     cout << answer;
// }

// antic 뺀 나머지 알파벳들 가져옴
// for (int k = 0; k < antic.length(); k++)
//     input.erase(remove(input.begin(), input.end(), antic[k]),
//                 input.end());
// 비트 마스킹
// hello 에서 ll 같은 중복제거 필요없는 로직임

// cout << bits[i] << " " << dfsBits[j] << " ";
// cout << bitCount(bits[i]) << " ";

// cout << bitCount(bits[0] | bits[1]) << " ";
