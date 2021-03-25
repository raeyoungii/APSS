#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string reverse(string::iterator& it) {
    char head = *(it++);
    if (head == 'b' || head == 'w') return string(1, head);
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

void solve() {
    string s; cin >> s;
    string::iterator it = s.begin();
    cout << reverse(it) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int C; cin >> C;
    while(C--) solve();
    return 0;
}
