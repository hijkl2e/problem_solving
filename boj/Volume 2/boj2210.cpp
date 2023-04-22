#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int A[5][5];
bool B[1000001];

void solve(int x, int y, int v, int l) {
	if (l == 6) {
		B[v] = true;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < 5 && 0 <= ny && ny < 5) {
			solve(nx, ny, 10 * v + A[nx][ny], l + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			solve(i, j, A[i][j], 1);
		}
	}
	int ans = accumulate(begin(B), end(B), 0);
	cout << ans << "\n";
	return 0;
}
