#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, board[101][101];
int cache[101][101];

int jump(int y, int x) {
    if (y >= n || x >= n) return 0;
    if (y == n - 1 && x == n - 1) return 1;
    int& ret = cache[y][x];
    if (ret != -1) return ret;
    int jumpSize = board[y][x];
    return ret = (jump(y + jumpSize, x) || jump(y, x + jumpSize));
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    memset(cache, -1, sizeof(cache));
    cout << (jump(0, 0) ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int C; cin >> C;
    while(C--) solve();
    return 0;
}
