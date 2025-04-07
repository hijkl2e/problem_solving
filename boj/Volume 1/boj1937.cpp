#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const int dx[4]{1, 0, -1, 0};
const int dy[4]{0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	vector<iii> B;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			B.push_back({A[i][j], i, j});
		}
	}
	sort(B.begin(), B.end());
	vector<vector<int>> dp(N, vector<int>(N, 1));
	for (auto &[v, x, y] : B) {
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < N && A[x][y] < A[nx][ny]) {
				dp[nx][ny] = max(dp[nx][ny], dp[x][y] + 1);
			}
		}
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
	}
	cout << ans << "\n";
	return 0;
}
