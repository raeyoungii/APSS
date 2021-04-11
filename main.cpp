#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int w, b;
int matrix[128][128];

void dfs(int y, int x, int n) {
    int tmp = matrix[y][x];
    for (int i = y; i < y + n; i++) {
        for (int j = x; j < x + n; j++) {
            if (tmp != matrix[i][j]) {
                dfs(y, x, n / 2);
                dfs(y + n / 2, x, n / 2);
                dfs(y, x + n / 2, n / 2);
                dfs(y + n / 2, x + n / 2, n / 2);
                return;
            }
        }
    }
    if (tmp == 0) w++;
    else b++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    dfs(0, 0, n);
    cout << w << nl << b << nl;
    return 0;
}
