#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

// -1은 아직 답이 계산되지 않았음을 의미한다.
// 1은 해당 입력들이 서로 대응됨을 의미한다.
// 0은 해당 입력들이 서로 대응되지 않음을 의미한다.
int cache[101][101];
// 패턴과 문자열
string W, S;
// 와일드카드 패턴 W[w..]가 문자열 S[s..]에 대응되는지 여부를 반환한다.
bool matchMemoized(int w, int s) {
    // 메모이제이션
    int& ret = cache[w][s];
    if (ret != -1) return ret;
    // W[w]와 S[s]를 맞춰나간다.
    if (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
        return ret = matchMemoized(w + 1, s + 1);
    }
    // 더이상 대응할 수 없으면 왜 while문이 끝났는지 확인한다.
    // 2. 패턴 끝에 도달해서 끝난 경우: 문자열도 끝났어야 참
    if (w == W.size()) return ret = (s == S.size());
    // 4. *를 만나서 끝난 경우: *에 몇 글자를 대응해야 할지 재귀 호출하면서 확인한다.
    if (W[w] == '*') {
        if (matchMemoized(w + 1, s) || (s < S.size() && matchMemoized(w, s + 1))) {
            return ret = 1;
        }
    }
    // 3. 이 외의 경우에는 모두 대응되지 않는다.
    return ret = 0;
}

void solve() {
     cin >> W;
    int n; cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        cin >> S;
        memset(cache, -1, sizeof(cache));
        if (matchMemoized(0, 0)) v.push_back(S);
    }
    sort(v.begin(), v.end());
    for (auto& i : v) cout << i << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int C; cin >> C;
    while(C--) solve();
    return 0;
}
