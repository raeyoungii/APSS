#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';
const int MOD = 1e9 + 7;

int cache[101];

// 2 * width 크기의 사각형을 채우는 방법의 수를 MOD로 나눈 나머지를 반환한다.
int tiling(int width) {
    // 기저사례: width가 1 이하 일때
    if (width <= 1) return 1;
    // 메모이제이션
    int& ret = cache[width];
    if (ret != -1) return ret;
    return ret = (tiling(width - 1) + tiling(width - 2)) % MOD;
}

void solve() {
    int n; cin >> n;
    memset(cache, -1, sizeof(cache));
    cout << tiling(n) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int C; cin >> C;
    while(C--) solve();
    return 0;
}
