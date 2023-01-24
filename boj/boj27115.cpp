#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{1, 0, -1, 0};
const int dy[4]{0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<vector<int>> D(N, vector<int>(M, -1));
	vector<queue<ii>> q(3001);
	while (K--) {
		int x{}, y{}, p{};
		cin >> x >> y >> p;
		--x, --y;
		D[x][y] = p;
		q[p].push({x, y});
	}
	for (int i = q.size() - 1; i > 0; --i) {
		while (q[i].size()) {
			auto [x, y] = q[i].front(); q[i].pop();
			for (int j = 0; j < 4; ++j) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (0 <= nx && nx < N && 0 <= ny && ny < M && D[nx][ny] < i - 1) {
					D[nx][ny] = i - 1;
					q[i - 1].push({nx, ny});
				}
			}
		}
	}
	int ans = N * M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (D[i][j] == -1) {
				--ans;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
