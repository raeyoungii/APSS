#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int n;
int cache[501], S[500];
int choices[101];

// 최대 증가 부분 수열 문제를 해결하는 완전 탐색 알고리즘
int lis(const vector<int>& A) {
    // 기저사례: A가 텅 비어있을 때
    if (A.empty()) return 0;
    int ret = 0;
    for (int i = 0; i < A.size(); i++) {
        vector<int> B;
        for (int j = i + 1; j < A.size(); j++) {
            if (A[i] < A[j]) B.push_back(A[j]);
            ret = max(ret, lis(B) + 1);
        }
    }
    return ret;
}

// 최대 증가 부분 수열 문제를 해결하는 동적 계획법 알고리즘 (1)
// S[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환한다.
int lis2(int start) {
    int& ret = cache[start];
    if (ret != -1) return ret;
    // 항상 S[start]는 있기 때문에 길이는 최하 1
    ret = 1;
    for (int next = start + 1; next < n; next++) {
        if (S[start] < S[next])
            ret = max(ret, lis2(next) + 1);
    }
    return ret;
}

// 최대 증가 부분 수열 문제를 해결하는 동적 계획법 알고리즘 (2)
// S[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환한다.
int lis3(int start) {
    int& ret = cache[start + 1];
    if (ret != -1) return ret;
    // 항상 S[start]는 있기 때문에 길이는 최하 1
    ret = 1;
    for (int next = start + 1; next < n; next++) {
        if (start == -1 || S[start] < S[next])
            ret = max(ret, lis3(next) + 1);
    }
    return ret;
}

int lis4(int start) {
    int& ret = cache[start + 1];
    if (ret != -1) return ret;
    // 항상 S[start]는 있기 때문에 길이는 최하 1
    ret = 1;
    int bestNext = -1;
    for (int next = start + 1; next < n; next++) {
        if (start == -1 || S[start] < S[next]) {
            int cand = lis4(next) + 1;
            if (cand > ret) {
                ret = cand;
                bestNext = next;
            }
        }
    }
    choices[start + 1] = bestNext;
    return ret;
}

// S[start]에서 시작하는 LIS를 seq에 저장한다.
void reconstruct(int start, vector<int>& seq) {
    if (start != -1) seq.push_back(S[start]);
    int next = choices[start + 1];
    if (next != -1) reconstruct(next, seq);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> S[i];
//    int maxLen = 0;
//    for (int begin = 0; begin < n; begin++) {
//        memset(cache, -1, sizeof(cache));
//        maxLen = max(maxLen, lis2(begin));
//    }
//    cout << maxLen << nl;
    memset(cache, -1, sizeof(cache));
    memset(choices, -1, sizeof(choices));
    cout << lis4(-1) - 1 << nl;
    vector<int> seq;
    reconstruct(-1, seq);
    for (int i = 0; i < seq.size(); i++) {
        cout << seq[i] << " \n" [i == seq.size() - 1];
    }
    for (int i = 0; i < n; i++) {
        cout << S[i] << " \n" [i == n - 1];
    }
    for (int i = 0; i < n; i++) {
        cout << choices[i] << " \n" [i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int C; cin >> C;
    while(C--) solve();
    return 0;
}
