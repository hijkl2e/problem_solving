#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{}, N{};
	cin >> M >> N;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<int>> D(N, vector<int>(M));
	queue<ii> q;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == 1) {
				q.push({i, j});
			}
		}
	}
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] == 0) {
				A[nx][ny] = 1;
				D[nx][ny] = D[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		ans = max(ans, *max_element(D[i].begin(), D[i].end()));
		if (count(A[i].begin(), A[i].end(), 0)) {
			ans = -1;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
