#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int coverType[4][3][2] = {
        {{0, 0}, {1, 0}, {0, 1}},
        {{0, 0}, {0, 1}, {1, 1}},
        {{0, 0}, {1, 0}, {1, 1}},
        {{0, 0}, {1, 0}, {1, -1}}
};

int dfs(vector<vector<int> >& board) {

}

void solve() {
    int H, W; cin >> H >> W;
    vector<vector<int> > board;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c; cin >> c;
            if (c == '#') board[i][j] = 1;
            else board[i][j] = 0;
        }
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
