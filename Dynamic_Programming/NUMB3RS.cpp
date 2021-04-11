#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int n, d, p, q;
// connected[i][j]: 마을 i, j가 연결되어 있나 여부
// deg[i]: 마을 i와 연결된 마을의 개수
int connected[51][51], deg[51];
double cache[51][101];

// 완전탐색
double search(vector<int>& path) {
    if (path.size() == d + 1) {
        if (path.back() != q) return 0.0;
        double ret = 1.0;
        for (int i = 0; i < path.size() - 1; i++) {
            ret /= deg[path[i]];
        }
        return ret;
    }
    double ret = 0.0;
    for (int there = 0; there < n; there++) {
        if (connected[path.back()][there]) {
            path.push_back(there);
            ret += search(path);
            path.pop_back();
        }
    }
    return ret;
}

// days일째에 here번 마을에 숨어 있다고 가정하고,
// 마지막 날에 q번 마을에 숨어 있을 조건부 확률을 반환한다.
double search2(int here, int days) {
    // 기저 사례: d일이 지난 경우
    if (days == d) return (here == q ? 1.0 : 0.0);
    // 메모이제이션
    double& ret = cache[here][days];
    if (ret > -0.5) return ret;
    ret = 0.0;
    for (int there = 0; there < n; there++) {
        if (connected[here][there])
            ret += search2(there, days + 1) / deg[here];
    }
    return ret;
}

double search3(int here, int days) {
    // 기저 사례: 0일 째
    if (days == 0) return (here == p ? 1.0 : 0.0);
    // 메모이제이션
    double& ret = cache[here][days];
    if (ret > -0.5) return ret;
    ret = 0.0;
    for (int there = 0; there < n; there++) {
        if (connected[here][there])
            ret += search3(there, days - 1) / deg[there];
    }
    return ret;
}

void solve() {
    cin >> n >> d >> p;
    memset(deg, 0, sizeof(deg));
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            cin >> connected[i][j];
            if (connected[i][j]) cnt++;
        }
        deg[i] = cnt;
    }
    int t; cin >> t;
    while (t--) {
        cin >> q;
        memset(cache, -1, sizeof(cache));
        cout.precision(8);
        cout << search3(q, d) << " ";
    }
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int C; cin >> C;
    while(C--) solve();
    return 0;
}
