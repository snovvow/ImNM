#include <algorithm>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;

int n, m, l, k;
int main(int argc, char *argv[]) {
    // input
    scanf("%d %d %d %d", &n, &m, &l, &k);
    int x, y;
    vector<pair<int, int>> v(k);

    for (int i = 0; i < k; i++) {
        scanf("%d %d", &x, &y);
        v[i] = {x, y};
    }
    int ans = 0;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            int cnt = 0;
            x = v[i].first;
            y = v[j].second;
            for (int a = 0; a < k; a++) {
                int nx = v[a].first;
                int ny = v[a].second;
                if (x <= nx && x + l >= nx && y <= ny && y + l >= ny)
                    cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    printf("%d", k - ans);

    return 0;
}
