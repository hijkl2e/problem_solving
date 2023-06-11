#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

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
	vector<vector<int>> D(N, vector<int>(M, -1));
	vector<vector<ii>> par(N, vector<ii>(M, {-1, -1}));
	queue<ii> q;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == -1) {
				D[i][j] = 0;
				q.push({i, j});
			}
		}
	}
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx1 = x + dx[i];
			int ny1 = y + dy[i];
			int nx2 = x + 2 * dx[i];
			int ny2 = y + 2 * dy[i];
			if (0 <= nx2 && nx2 < N && 0 <= ny2 && ny2 < M
					&& A[nx1][ny1] == A[nx2][ny2] && A[nx2][ny2] != -2) {
				if (D[nx2][ny2] == -1) {
					D[nx2][ny2] = D[x][y] + 1;
					q.push({nx2, ny2});
					par[nx2][ny2] = {x, y};
				} else if (D[nx2][ny2] == D[x][y] + 1) {
					auto &[px, py] = par[nx2][ny2];
					if (A[px][py] > A[x][y]) {
						par[nx2][ny2] = {x, y};
					}
				}
			}
		}
	}
	int r{}, c{};
	cin >> r >> c;
	if (D[--r][--c] == -1) {
		cout << "impossible\n";
		return 0;
	}
	vector<int> ans;
	while (A[r][c] != -1) {
		ans.push_back(A[r][c]);
		auto &[px, py] = par[r][c];
		r = px, c = py;
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
	}
	return 0;
}
