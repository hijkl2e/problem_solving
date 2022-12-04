#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;
const int dx[8]{1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8]{0, 1, 0, -1, 1, -1, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		cin.ignore();
		vector<string> S(N);
		for (int i = 0; i < N; ++i) {
			getline(cin, S[i]);
		}
		vector<deque<bool>> A(N, deque<bool>(M));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (S[i][j] == '#') {
					continue;
				}
				int cnt{};
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx == -1 || nx == N || ny == -1 || ny == M || S[nx][ny] == '.') {
						++cnt;
					}
				}
				A[i][j] = cnt == 4;
			}
		}
		vector<vector<int>> d(N, vector<int>(M, INF));
		vector<vector<ii>> p(N, vector<ii>(M, {-1, -1}));
		deque<ii> dq;
		for (int i = 0; i < N; ++i) {
			if (S[i][0] == '#') {
				d[i][0] = 0;
				dq.push_front({i, 0});
			} else if (A[i][0]) {
				d[i][0] = 1;
				dq.push_back({i, 0});
			}
		}
		while (!dq.empty()) {
			auto [x, y] = dq.front();
			dq.pop_front();
			for (int k = 4; k < 8; ++k) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx == -1 || nx == N || ny == -1 || ny == M) {
					continue;
				}
				int nd = d[x][y] + (S[nx][ny] == '#' ? 0 : A[nx][ny] ? 1 : INF);
				if (d[nx][ny] > nd) {
					d[nx][ny] = nd;
					p[nx][ny] = {x, y};
					if (S[nx][ny] == '#') {
						dq.push_front({nx, ny});
					} else {
						dq.push_back({nx, ny});
					}
				}
			}
		}
		int minx = -1;
		for (int i = 0; i < N; ++i) {
			if (d[i][M - 1] == INF) {
				continue;
			}
			if (minx == -1 || d[minx][M - 1] > d[i][M - 1]) {
				minx = i;
			} 
		}
		if (minx == -1) {
			cout << "NO\n";
			continue;
		}
		ii now = {minx, M - 1};
		while (true) {
			auto &[x, y] = now;
			if (y == -1) {
				break;
			}
			S[x][y] = '#';
			now = p[x][y];
		}
		cout << "YES\n";
		for (int i = 0; i < N; ++i) {
			cout << S[i] << "\n";
		}
	}
	return 0;
}
