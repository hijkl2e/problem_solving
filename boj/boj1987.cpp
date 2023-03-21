#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int R, C, ans;
vector<string> A;
vector<vector<int>> dp;

void dfs(int x, int y, int z) {
	z |= 1 << (A[x][y] - 'A');
	if (dp[x][y] == z) {
		return;
	}
	dp[x][y] = z;
	ans = max(ans, __builtin_popcount(z));
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < R && 0 <= ny && ny < C && (z & (1 << (A[nx][ny] - 'A'))) == 0) {
			dfs(nx, ny, z);
		}
	}
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
	dp.assign(R, vector<int>(C));
	dfs(0, 0, 0);
	cout << ans << "\n";
	return 0;
}
