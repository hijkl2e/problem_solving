#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int R, C, K, ans;
vector<string> A;

void solve(int x, int y, int k) {
	if (k == K) {
		if (x == 0 && y == C - 1) {
			++ans;
		}
		return;
	}
	A[x][y] = 'T';
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < R && 0 <= ny && ny < C && A[nx][ny] == '.') {
			solve(nx, ny, k + 1);
		}
	}
	A[x][y] = '.';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> R >> C >> K;
	cin.ignore();
	A.resize(R);
	for (int i = 0; i < R; ++i) {
		getline(cin, A[i]);
	}
	solve(R - 1, 0, 1);
	cout << ans << "\n";
	return 0;
}
