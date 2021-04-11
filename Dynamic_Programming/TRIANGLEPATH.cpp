#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';
// MAX_NUMBER: 한 칸에 들어갈 숫자의 최대치
const int MAX_NUMBER = 100000;

int n, triangle[100][100];
int cache[100][100][MAX_NUMBER * 100 + 1];
int cache2[100][100];

// (y, x) 위치까지 내려오기 전에 만난 숫자들의 합이 sum 일 때
// 맨 아래줄까지 내려가면서 얻을 수 있는 최대 경로를 반환한다.
int path1(int y, int x, int sum) {
    // 기저 사례: 맨 아래 줄까지 도달했을 경우
    if (y == n - 1) return sum + triangle[y][x];
    // 메모이제이션
    int& ret = cache[y][x][sum];
    if (ret != -1) return ret;
    sum += triangle[y][x];
    return ret = max(path1(y + 1, x, sum), path1(y + 1, x + 1, sum));
}

// (y, x) 위치부터 맨 아래줄까지 내려가면서 얻을 수 있는 최대 경로의 합을 반환한다.
int path2(int y, int x) {
    // 기저 사례
    if (y == n - 1) return triangle[y][x];
    // 메모이제이션
    int& ret = cache2[y][x];
    if (ret != -1) return ret;
    return ret = max(path2(y + 1, x), path2(y + 1, x + 1)) + triangle[y][x];
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> triangle[i][j];
        }
    }
    memset(cache2, -1, sizeof(cache2));
    cout << path2(0, 0) << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int C; cin >> C;
    while(C--) solve();
    return 0;
}
