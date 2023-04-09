#include <algorithm>
#include <iostream>

using namespace std;
int blueCount;
int redCount;
int isAnotherColor;
int m = 500001;
int cnt;

void set() {
    isAnotherColor = 0;
    m = cnt < m ? cnt : m;
    cnt = 0;
}

// 직접옮길 필요없이 고립된 ? 녀석을 구하면 끝..
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;

    char beforeChar;
    string balls;
    // 볼의 총 개수
    cin >> n;
    cin >> balls;
    int i;
    for (i = 0; i < n; i++) // 빨간색을 왼쪽으로 모을 경우
    {
        if (balls[i] == 'B')
            isAnotherColor = 1; // 파란색이 나오는지 체크한다.
        if (isAnotherColor && balls[i] == 'R')
            cnt++; // 파란색이 나왔었는지 확인하고, 빨간색인지 확인하여 개수를
                   // 세준다.
    }
    set(); // 다음 반복문을 위해 사용한 변수를 초기화를 해주고, 최소값을 구한다.
    for (i = n - 1; i >= 0; i--) // 빨간색을 오른쪽으로 모을 경우
    {
        if (balls[i] == 'B')
            isAnotherColor = 1;
        if (isAnotherColor && balls[i] == 'R')
            cnt++;
    }
    set();

    for (i = 0; i < n; i++) // 파란색을 왼쪽으로 모을 경우
    {
        if (balls[i] == 'R')
            isAnotherColor = 1;
        if (isAnotherColor && balls[i] == 'B')
            cnt++;
    }
    set();
    for (i = n - 1; i >= 0; i--) // 파란색을 오른쪽으로 모을 경우
    {
        if (balls[i] == 'R')
            isAnotherColor = 1;
        if (isAnotherColor && balls[i] == 'B')
            cnt++;
    }
    set();

    cout << m;

    return 0;
}