#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[8]{-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8]{-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<vector<int>> D(N, vector<int>(M, -1));
	queue<ii> q;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == '.') {
				D[i][j] = 0;
				q.push({i, j});
			}
		}
	}
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 8; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && isdigit(A[nx][ny]) && --A[nx][ny] == '0') {
				D[nx][ny] = D[x][y] + 1;
				A[nx][ny] = '.';
				q.push({nx, ny});
			}
		}
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		ans = max(ans, *max_element(D[i].begin(), D[i].end()));
	}
	cout << ans << "\n";
	return 0;
}
