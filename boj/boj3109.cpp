#include <bits/stdc++.h>

using namespace std;

int R, C;
vector<string> A;

bool solve(int x, int y) {
	A[x][y] = 'x';
	if (y == C - 1) {
		return true;
	}
	for (int i = -1; i < 2; ++i) {
		int nx = x + i;
		if (0 <= nx && nx < R && A[nx][y + 1] == '.' && solve(nx, y + 1)) {
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> R >> C;
	cin.ignore();
	A.resize(R);
	for (int i = 0; i < R; ++i) {
		getline(cin, A[i]);
	}
	int ans{};
	for (int i = 0; i < R; ++i) {
		if (solve(i, 0)) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
