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
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<vector<int>> D(N, vector<int>(M, -1));
	int ans{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == 'W') {
				continue;
			}
			for (int k = 0; k < N; ++k) {
				fill(D[k].begin(), D[k].end(), -1);
			}
			queue<ii> q;
			D[i][j] = 0;
			q.push({i, j});
			while (q.size()) {
				auto [x, y] = q.front(); q.pop();
				for (int k = 0; k < 4; ++k) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] == 'L' && D[nx][ny] == -1) {
						D[nx][ny] = D[x][y] + 1;
						q.push({nx, ny});
					}
				}
				ans = max(ans, D[x][y]);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
