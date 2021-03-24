#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
bool areFriends[10][10];

int dfs(bool vst[10]) {
    int firstFree = -1;
    for (int i = 0; i < n; i++) {
        if (!vst[i]) { firstFree = i; break; }
    }
    if (firstFree == -1) return 1;
    int ret = 0;
    for (int i = firstFree + 1; i < n; i++) {
        if (!vst[i] && areFriends[firstFree][i]) {
            vst[firstFree] = vst[i] = true;
            ret += dfs(vst);
            vst[firstFree] = vst[i] = false;
        }
    }
    return ret;
}

void solve() {
    memset(areFriends, 0, sizeof(areFriends));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        areFriends[a][b] = areFriends[b][a] = true;
    }
    bool vst[10] = {false};
    cout << dfs(vst) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int C; cin >> C;
    while(C--) solve();
    return 0;
}
