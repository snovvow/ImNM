#include <algorithm>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;

int N, K, Start, End, Cnt, Answer;

int Belt[201];
bool Visit[201];
queue<int> Robot;

void Move_Belt() {
    Start--;
    End--;
    if (Start < 1)
        Start = 2 * N;
    if (End < 1)
        End = 2 * N;
}

void Move_Robot() {
    int Size = Robot.size();
    for (int i = 0; i < Size; i++) {
        int Cur = Robot.front();
        Visit[Cur] = false;
        Robot.pop();

        if (Cur == End)
            continue;

        int Next = Cur + 1;
        if (Next > 2 * N)
            Next = 1;
        if (Belt[Next] >= 1 && Visit[Next] == false) {
            Belt[Next]--;
            if (Belt[Next] == 0)
                Cnt++;
            if (Next == End)
                continue;
            Visit[Next] = true;
            Robot.push(Next);

        } else {
            Visit[Cur] = true;
            Robot.push(Cur);
        }
    }
}

void Make_Robot() {
    if (Visit[Start] == false && Belt[Start] >= 1) {
        Visit[Start] = true;
        Belt[Start]--;
        Robot.push(Start);

        if (Belt[Start] == 0)
            Cnt++;
    }
}

int main(int argc, char *argv[]) {
    // input
    scanf("%d %d ", &N, &K);
    int input;

    for (int i = 1; i <= 2 * N; i++) {
        scanf("%d", &input);
        Belt[i] = input;
    }

    Start = 1;
    End = N;

    while (Cnt < K) {
        Answer++;

        Move_Belt();
        Move_Robot();
        Make_Robot();
    }
    printf("%d", Answer);
    // 내구도 0인 칸의 개수가 k개 이상이라면 과정을 종료.
    return 0;
}
