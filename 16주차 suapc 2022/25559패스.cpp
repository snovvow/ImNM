//임의의 연속한 k개의 칸에... 딸기 토마토를 심는다!
// 순차적으로 포문 돌리면서 1인 숫자 발견하면 dfs 돌리기
// ( dfs 돌릴 조건은 1이 아닌경우..? )
// dfs 돌릴때 두방향으로 돌려야함
// 오른쪽으로 가는 방향 , 아래로 내려가는 방향
// 오른쪽 , 아랫쪽이든 방문한놈은 2로바꿈

// 백트레킹으로 K의 조건을 만족하고 , 0 이 아닌 수라면 돌아가면서
// 2같은 수로 바꿈 그자리가 만약 2였다면
// 좌표 우선순위 큐로 넣어서 삽입!

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    if (N == 1) {
        cout << 1;
        return 0;
    }
    if (N % 2 == 1) {
        cout << -1;
        return 0;
    }

    int left = N;
    int right = 1;

    for (int i = 0; i < N / 2; i++) {
        cout << N - 2 * i << " " << 1 + 2 * i << " ";
    }
}

// N = int(sys.stdin.readline())
// if N == 1:
//     print(1)
//     exit(0)
// if N % 2 == 1:
//     print(-1)
//     exit(0)

// answer = []
// left = N
// right = 1
// while(True):
//     answer.append(str(left))
//     left -= 2
//     if len(answer) == N:
//         break
//     answer.append(str(right))
//     right += 2
//     if len(answer) == N:
//         break

// print(' '.join(answer))