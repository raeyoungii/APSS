#include <bits/stdc++.h>

#define MAX_SIZE 1100000

using namespace std;
typedef long long ll;

char decompressed[MAX_SIZE][MAX_SIZE];

void decompress(string::iterator& it, int y, int x, int size) {
    // 한 글자를 검사할 때마다 반복자를 한 칸 앞으로 옮긴다.
    char head = *(it++);
    // 기저 사례: 첫 글자가 b 또는 w인 경우
    if (head == 'b' || head == 'w') {
        for (int dy = 0; dy < size; dy++) {
            for (int dx = 0; dx < size; dx++) {
                decompressed[y + dy][x + dx] = head;
            }
        }
    } else {
        int half = size / 2;
        decompress(it, y, x, half);
        decompress(it, y, x + half, half);
        decompress(it, y + half, x, half);
        decompress(it, y + half, x + half, half);
    }
}

void solve() {
    string s; cin >> s;
    int size = 1;
    for (auto& c : s) { if (c == 'x') size *= 4; }
    string::iterator it = s.begin();
    decompress(it, 0, 0, size);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int C; cin >> C;
    while (C--) solve();
    return 0;
}

