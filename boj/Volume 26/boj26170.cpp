#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

vector<vector<int>> A(5, vector<int>(5));
int ans;

void solve(int z, int r, int c, int a) {
	if (a == 3) {
		ans = min(ans, z);
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int nx = r + dx[i];
		int ny = c + dy[i];
		if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && A[nx][ny] > -1) {
			int t = A[nx][ny];
			A[nx][ny] = -1;
			solve(z + 1, nx, ny, a + t);
			A[nx][ny] = t;
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
	int r{}, c{};
	cin >> r >> c;
	A[r][c] = -1;
	ans = INF;
	solve(0, r, c, 0);
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
