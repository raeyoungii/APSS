#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int solve(vector<int> &h, int left, int right) {
    // 기저사례: 판자가 하나밖에 없는 경우
    if (left == right) return h[left];
    int mid = (left + right) / 2;
    // 가장 큰 직사각형이 왼쪽 or 오른쪽에 있을때
    int ret = max(solve(h, left, mid), solve(h, mid + 1, right));
    // 가장 큰 직사각형이 두 부분에 걸칠때
    int lo = mid, hi = mid + 1;
    int height = min(h[lo], h[hi]);
    // [mid, mid + 1]만 포함하는 너비 2인 사각형을 고려
    ret = max(ret, height * 2);
    // 사각형이 전체를 덮을 때까지 확장
    while (left < lo || hi < right) {
        // 항상 높이가 더 높은 쪽으로 확장
        if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
            hi++;
            height = min(height, h[hi]);
        } else {
            lo--;
            height = min(height, h[lo]);
        }
        ret = max(ret, height * (hi - lo + 1));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int C; cin >> C;
    while(C--) {
        int n; cin >> n;
        vector<int> h(n);
        for (int i = 0; i < n; i++) cin >> h[i];
        cout << solve(h, 0, n - 1) << "\n";
    }
    return 0;
}
