#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<int>> dp(N, vector<int>(M));
	priority_queue<iii> pq;
	dp[0][0] = 1;
	pq.push({A[0][0], 0, 0});
	while (pq.size()) {
		auto [h, x, y] = pq.top(); pq.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && A[x][y] > A[nx][ny]) {
				if (dp[nx][ny] == 0) {
					pq.push({A[nx][ny], nx, ny});
				}
				dp[nx][ny] += dp[x][y];
			}
		}
	}
	cout << dp[N - 1][M - 1] << "\n";
	return 0;
}
