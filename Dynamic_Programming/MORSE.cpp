#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';
const int M = 1e9 + 100;

int skip;
int bino[201][201];

void generate(int n, int m, const string& s) {
    if (n == 0 && m == 0) { cout << s << nl; return; }
    if (n > 0) generate(n - 1, m, s + "-");
    if (m > 0) generate(n, m - 1, s + "o");
}

void generate2(int n, int m, const string& s) {
    if (skip < 0) return;
    if (n == 0 && m == 0) {
        if (skip == 0) cout << s << nl;
        skip--;
        return;
    }
    if (n > 0) generate2(n - 1, m, s + "-");
    if (m > 0) generate2(n, m - 1, s + "o");
}

// 필요한 모든 이항계수를 미리 계산해 둔다.
void calcBino() {
    memset(bino, 0, sizeof(bino));
    for (int i = 0; i <= 200; i++) {
        bino[i][0] = bino[i][i] = 1;
        for (int j = 1; j < i; j++) {
            bino[i][j] = min(M, bino[i - 1][j - 1] + bino[i - 1][j]);
        }
    }
}

void generate3(int n, int m, const string& s) {
    if (skip < 0) return;
    if (n == 0 && m == 0) {
        if (skip == 0) cout << s << nl;
        skip--;
        return;
    }
    if (bino[n + m][n] <= skip) { skip -= bino[n + m][n]; return; }
    if (n > 0) generate3(n - 1, m, s + "-");
    if (m > 0) generate3(n, m - 1, s + "o");
}

string kth(int n, int m, int skip) {
    if (n == 0) return string(m, 'o');
    if (skip < bino[n + m - 1][n - 1]) return "-" + kth(n - 1, m, skip);
    return "o" + kth(n, m - 1, skip - bino[n + m - 1][n - 1]);
}

void solve() {
    int n, m; cin >> n >> m >> skip;
    skip--;
    calcBino();
    string s;
    generate3(n, m, s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int C; cin >> C;
    while(C--) solve();
    return 0;
}
