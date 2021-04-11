#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';
const ll NEGINF = numeric_limits<ll>::min();

int n, m, A[100], B[100];
// idxA, idxB가 -1 부터 시작하므로 100 + 1
int cache[101][101];

// min(A[idxA], B[idxB], max(A[idxA], B[idxB])로 시작하는
// 합친 증가 부분 수열의 최대 길이를 반환한다.
// 단, idxA == idxB == -1 혹은 A[idxA] != B[idxB]라고 가정한다.
int jlis(int idxA, int idxB) {
    // 메모이제이션
    int& ret = cache[idxA + 1][idxB + 1];
    if (ret != -1) return ret;
    // A[idxA], B[idxB]가 이미 존재하므로 2개는 항상 있다.
    ret = 2;
    ll a = (idxA == -1 ? NEGINF : A[idxA]);
    ll b = (idxB == -1 ? NEGINF : B[idxB]);
    ll maxElement = max(a, b);
    // 다음 원소를 찾는다.
    for (int nextA = idxA + 1; nextA < n; nextA++) {
        if (maxElement < A[nextA])
            ret = max(ret, jlis(nextA, idxB) + 1);
    }
    for (int nextB = idxB + 1; nextB < m; nextB++) {
        if (maxElement < B[nextB])
            ret = max(ret, jlis(idxA, nextB) + 1);
    }
    return ret;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < m; i++) cin >> B[i];
    memset(cache, -1, sizeof(cache));
    cout << jlis(-1, -1) - 2 << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int C; cin >> C;
    while(C--) solve();
    return 0;
}
