#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';
const int MOD = 1e7;

int cache[101][101];

int poly(int n, int first) {
    // 기저 사례: n == first
    if (n == first) return 1;
    int& ret = cache[n][first];
    if (ret != -1) return ret;
    ret = 0;
    for (int second = 1; second <= n - first; second++) {
      int add = second + first - 1;
      add *= poly(n - first, second);
      add %= MOD;
      ret += add;
      ret %= MOD;
    }
    return ret;
}

void solve() {
    int n; cin >> n;
    memset(cache, -1, sizeof(cache));
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += poly(n, i);
      sum %= MOD;
    }
    cout << sum << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int C; cin >> C;
    while(C--) solve();
    return 0;
}
