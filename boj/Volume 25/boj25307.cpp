#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<int>> d1(N, vector<int>(M, INF));
	vector<vector<int>> d2(N, vector<int>(M, INF));
	for (int k = 0; k < 2; ++k) {
		vector<vector<int>> &D = k ? d2 : d1;
		queue<ii> q;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (A[i][j] == k + 3) {
					D[i][j] = 0;
					q.push({i, j});
				}
			}
		}
		while (q.size()) {
			auto [x, y] = q.front(); q.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < N && 0 <= ny && ny < M && D[nx][ny] == INF
						&& (k == 0 || (A[nx][ny] != 1 && d1[nx][ny] > K))) {
					D[nx][ny] = D[x][y] + 1;
					q.push({nx, ny});
				}
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == 2) {
				ans = min(ans, d2[i][j]);
			}
		}
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
