#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

vector<vector<int>> A(5, vector<int>(5));

vector<int> solve(int sx, int sy) {
	vector<vector<int>> D(5, vector<int>(5, INF));
	queue<ii> q;
	D[sx][sy] = 0;
	q.push({sx, sy});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && A[nx][ny] > -1 && D[nx][ny] == INF) {
				D[nx][ny] = D[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	vector<int> ret(7);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (A[i][j] > 0) {
				ret[A[i][j]] = D[i][j];
			}
		}
	}
	return ret;
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
	vector<vector<int>> B(7);
	B[0] = solve(r, c);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (A[i][j] > 0) {
				B[A[i][j]] = solve(i, j);
			}
		}
	}
	vector<vector<int>> dp(128, vector<int>(7, INF));
	dp[1][0] = 0;
	for (int i = 1; i < 128; ++i) {
		for (int j = 0; j < 7; ++j) {
			if (dp[i][j] == INF) {
				continue;
			}
			for (int k = 1; k < 7; ++k) {
				int &val = dp[i | (1 << k)][k];
				val = min(val, dp[i][j] + B[j][k]);
			}
		}
	}
	int ans = *min_element(dp.back().begin(), dp.back().end());
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
