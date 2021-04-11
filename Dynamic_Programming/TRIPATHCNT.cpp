#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int n, triangle[100][100];
int cache[100][100];
int countCache[100][100];

// (y, x) 위치부터 맨 아래줄까지 내려가면서 얻을 수 있는 최대 경로의 합을 반환한다.
int path2(int y, int x) {
    // 기저 사례
    if (y == n - 1) return triangle[y][x];
    // 메모이제이션
    int& ret = cache[y][x];
    if (ret != -1) return ret;
    return ret = max(path2(y + 1, x), path2(y + 1, x + 1)) + triangle[y][x];
}

// (y, x)에서 시작해서 맨 아래줄까지 내려가는 경로 중 최대 경로의 개수를 반환한다.
int count(int y, int x) {
    // 기저사례: 맨 아래줄에 도달한 경우
    if (y == n - 1) return 1;
    // 메모이제이션
    int& ret = countCache[y][x];
    if (ret != -1) return ret;
    ret = 0;
    if (path2(y + 1, x + 1) >= path2(y + 1, x)) ret += count(y + 1, x + 1);
    if (path2(y + 1, x + 1) <= path2(y + 1, x)) ret += count(y + 1, x);
    return ret;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> triangle[i][j];
        }
    }
    memset(cache, -1, sizeof(cache));
    memset(countCache, -1, sizeof(countCache));
    cout << count(0, 0) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int C; cin >> C;
    while(C--) solve();
    return 0;
}
