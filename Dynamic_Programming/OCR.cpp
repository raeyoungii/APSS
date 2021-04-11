#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int n, m;
// 분류기가 반환한 문장. 단어 번호로 변환되어 있음
int R[100];
// T[i][j] = i단어 이후에 j단어가 나올 확률의 로그 값
double T[501][501];
// M[i][j] = i단어가 j단어로 분류될 확률의 로그 값
double M[501][501];
int choice[102][502];
double cache[102][502]; // 1로 초기화한다.
// 입력받은 단어들의 목록
string corpus[501];

// Q[segment] 이후를 채워서 얻을 수 있는 최대 g() 곱의 로그 값을 반환한다.
// Q[segment] == previousMatch 라고 가정한다.
double recognize(int segment, int previousMatch) {
    if (segment == n) return 0;
    double& ret = cache[segment][previousMatch];
    if (ret != 1.0) return ret;
    ret = -1e200; // log(0) = 음의 무한대에 해당하는 값
    int& choose = choice[segment][previousMatch];
    // R[segment]에 대응되는 단어를 찾는다.
    for (int thisMatch = 1; thisMatch <= m; thisMatch++) {
        // g(thisMatch) = T(previousMatch, thisMatch) * M(thisMatch, R[segment])
        double cand = T[previousMatch][thisMatch] + M[thisMatch][R[segment]] + recognize(segment + 1, thisMatch);
        if (ret < cand) { ret = cand; choose = thisMatch; }
    }
    return ret;
}

string reconstruct(int segment, int previousMatch) {
    int choose = choice[segment][previousMatch];
    string ret = corpus[choose];
    if (segment < n - 1)
        ret = ret + " " + reconstruct(segment + 1, choose);
    return ret;
}

void solve() {
    int q; cin >> m >> q;
    for (int i = 1; i <= m; i++) cin >> corpus[i];
    for (int i = 0; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> T[i][j];
            T[i][j] = log(T[i][j]);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
          cin >> M[i][j];
          M[i][j] = log(M[i][j]);
        }
    }
    while (q--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                cache[i][j] = 1.0;
            }
        }
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 1; j <= m; j++) {
                if (s == corpus[j]) { R[i] = j; break; }
            }
        }
        recognize(0, 0);
        cout << reconstruct(0, 0) << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// TODO
