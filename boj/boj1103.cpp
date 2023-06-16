#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N, M;
vector<string> A;
vector<vector<int>> dp;
vector<deque<bool>> vst;

int solve(int x, int y) {
	if (vst[x][y]) {
		return -1;
	} else if (dp[x][y]) {
		return dp[x][y];
	}
	vst[x][y] = true;
	dp[x][y] = 1;
	int z = A[x][y] - '0';
	for (int i = 0; i < 4; ++i) {
		int nx = x + z * dx[i];
		int ny = y + z * dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] != 'H') {
			int res = solve(nx, ny);
			if (res == -1) {
				return dp[x][y] = -1;
			}
			dp[x][y] = max(dp[x][y], solve(nx, ny) + 1);
		}
	}
	vst[x][y] = false;
	return dp[x][y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	cin.ignore();
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	dp.assign(N, vector<int>(M));
	vst.assign(N, deque<bool>(M));
	cout << solve(0, 0) << "\n";
	return 0;
}
