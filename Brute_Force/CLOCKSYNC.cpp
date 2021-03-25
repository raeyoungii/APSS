#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 987654321, SWITCHES = 10, CLOCKS = 16;
const char linked[SWITCHES][CLOCKS + 1] = {
        "xxx.............",
        "...x...x.x.x....",
        "....x.....x...xx",
        "x...xxxx........",
        "......xxx.x.x...",
        "x.x...........xx",
        "...x..........xx",
        "....xx.x......xx",
        ".xxxxx..........",
        "...xxx...x...x.."
};

bool areAligned(vector<int>& clocks) {
    for (int i = 0; i < CLOCKS; i++) {
        if (clocks[i] != 12) return false;
    }
    return true;
}

void push(vector<int>& clocks, int swtch) {
    for (int i = 0; i < CLOCKS; i++) {
        if (linked[swtch][i] == 'x') {
            clocks[i] = (clocks[i] + 2) % 12 + 1;
        }
    }
}

int dfs(vector<int>& clocks, int swtch) {
    if (swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;
    int ret = INF;
    for (int i = 0; i < 4; i++) {
        ret = min(ret, i + dfs(clocks, swtch + 1));
        push(clocks, swtch);
    }
    return ret;
}

void solve() {
    vector<int> clocks(16);
    for (int i = 0; i < 16; i++) cin >> clocks[i];
    int ans = dfs(clocks, 0);
    if (ans == INF) ans = -1;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int C; cin >> C;
    while(C--) solve();
    return 0;
}
