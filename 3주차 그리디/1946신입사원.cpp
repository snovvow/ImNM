/*

 백준 1946 문제
 소가 길을 건너간 이유
*/

#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

struct volunteer {
    int document;
    int interview;

    //생성자
    volunteer(int Cdocument, int Cinterview) {
        document = Cdocument;
        interview = Cinterview;
    }

    bool operator<(const volunteer &a) const { return document < a.document; }
};

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);

    for (int k = 0; k < T; k++) {
        // test case
        int n;
        vector<volunteer> v;
        int document, interview;

        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &document, &interview);
            v.push_back(volunteer(document, interview));
        }

        sort(v.begin(), v.end());

        int result = 1;

        int max = v[0].interview;

        for (int i = 1; i < n; i++) {
            if (max > v[i].interview) {
                // printf("%d %d \n", v[i].document, v[i].interview);
                result++;
                max = v[i].interview;
            }
        }

        printf("%d\n", result);
    }
}