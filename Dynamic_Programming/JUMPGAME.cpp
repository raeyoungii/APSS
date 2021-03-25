#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, board[101][101];
int cache[101][101];

int jump(int y, int x) {
    if (y >= n || x >= n) return 0;
    if (y == n - 1 && x == n - 1) return 1;
    int &ret = cache[y][x];
    if (ret != -1) return ret;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int C; cin >> C;
    while(C--) solve();
    return 0;
}
