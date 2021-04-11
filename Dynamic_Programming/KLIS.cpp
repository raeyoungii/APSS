#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';
const int MAX = 2e9 + 1;

int n;
int cacheLen[501], cacheCnt[501], S[500];

// S[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환한다.
int lis3(int start) {
    int& ret = cacheLen[start + 1];
    if (ret != -1) return ret;
    // 항상 S[start]는 있기 때문에 길이는 최하 1
    ret = 1;
    for (int next = start + 1; next < n; next++) {
        if (start == -1 || S[start] < S[next])
            ret = max(ret, lis3(next) + 1);
    }
    return ret;
}

// S[start]에서 시작하는 최대 증가 부분 수열의 수를 반환한다.
int count(int start) {
    if (lis3(start) == 1) return 1;
    // 메모이제이션
    int& ret = cacheCnt[start + 1];
    if (ret != -1) return ret;
    ret = 0;
    for (int next = start + 1; next < n; next++) {
        if ((start == -1 || S[start] < S[next]) && lis3(start) == lis3(next) + 1)
            ret = min<ll>(MAX, (ll) ret + count(next));
    }
    return ret;
}

void reconstruct(int start, int skip, vector<int>& lis) {
    // 1. S[start]는 항상 LIS에 포함된다.
    if (start != - 1) lis.push_back(S[start]);
    // 2. 뒤에 올 수 있는 숫자들과 위치의 목록을 만든다.
    // (숫자, 숫자의 위치)의 목록이 된다.
    vector<pair<int, int> > followers;
    for (int next = start + 1; next < n; next++) {
        if ((start == -1 || S[start] < S[next]) && lis3(start) == lis3(next) + 1)
            followers.emplace_back(S[next], next);
    }
    sort(followers.begin(), followers.end());
    // 3. k번째 LIS의 다음 숫자를 찾는다.
    for (int i = 0; i < followers.size(); i++) {
        // 이 숫자를 뒤에 이어서 만들 수 있는 LIS의 개수를 본다.
        int idx = followers[i].second;
        int cnt = count(idx);
        if (cnt <= skip) skip -= cnt;
        else { reconstruct(idx, skip, lis); break; }
    }
}

void solve() {
    int skip; cin >> n >> skip;
    skip--;
    for (int i = 0; i < n; i++) cin >> S[i];
    memset(cacheLen, -1, sizeof(cacheLen));
    memset(cacheCnt, -1, sizeof(cacheCnt));
    cout << lis3(-1) - 1 << nl;
    vector<int> lis;
    reconstruct(-1, skip, lis);
    for (int i = 0; i < lis.size(); i++) {
        cout << lis[i] << " \n" [i == lis.size() - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int C; cin >> C;
    while(C--) solve();
    return 0;
}

// TODO
