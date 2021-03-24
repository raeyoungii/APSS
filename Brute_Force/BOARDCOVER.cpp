#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int coverType[4][3][2] = {
        {{0, 0}, {1, 0}, {0, 1}},
        {{0, 0}, {0, 1}, {1, 1}},
        {{0, 0}, {1, 0}, {1, 1}},
        {{0, 0}, {1, 0}, {1, -1}}
};
int H, W;

bool chk(vector<vector<int> >& board, int y, int x, int type, int delta) {
    bool ok = true;
    for (int i = 0; i < 3; i++) {
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];
        if (ny < 0 || ny >= H || nx < 0 || nx >= W) ok = false;
        else if ((board[ny][nx] += delta) > 1) ok = false;
    }
    return ok;
}

int dfs(vector<vector<int> > &board) {
    int y = -1, x = -1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (board[i][j] == 0) { y = i; x = j; goto here; }
        }
    } here:;
    if (y == -1) return 1;
    int ret = 0;
    for (int type = 0; type < 4; type++) {
        if (chk(board, y, x, type, 1)) ret += dfs(board);
        chk(board, y, x, type, -1);
    }
    return ret;
}

void solve() {
    cin >> H >> W;
    vector<vector<int> > board(20, vector<int>(20));
    int cnt = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c; cin >> c;
            if (c == '#') board[i][j] = 1;
            else {
                board[i][j] = 0;
                cnt++;
            }
        }
    }
    if (cnt % 3 == 0) cout << dfs(board) << "\n";
    else cout << "0\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int C; cin >> C;
    while(C--) solve();
    return 0;
}
