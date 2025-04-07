#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 5e8;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N, M;
vector<string> A;

vector<vector<int>> bfs(int sx, int sy) {
	vector<vector<int>> D(N, vector<int>(M, INF));
	deque<ii> dq;
	D[sx][sy] = 0;
	dq.push_back({sx, sy});
	while (dq.size()) {
		auto [x, y] = dq.front(); dq.pop_front();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] != '*') {
				int nd = D[x][y] + (A[nx][ny] == '#');
				if (D[nx][ny] > nd) {
					D[nx][ny] = nd;
					if (A[nx][ny] == '#') {
						dq.push_back({nx, ny});
					} else {
						dq.push_front({nx, ny});
					}
				}
			}
		}
	}
	return D;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		cin >> N >> M;
		cin.ignore();
		A.resize(N + 2);
		A[0] = A[N + 1] = string(M + 2, '.');
		for (int i = 1; i <= N; ++i) {
			getline(cin, A[i]);
			A[i] = "." + A[i] + ".";
		}
		int px1{}, py1{}, px2{}, py2{};
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				if (A[i][j] == '$') {
					if (px1) {
						px2 = i, py2 = j;
					} else {
						px1 = i, py1 = j;
					}
				}
			}
		}
		N += 2;
		M += 2;
		vector<vector<int>> d1, d2, d3;
		d1 = bfs(0, 0);
		d2 = bfs(px1, py1);
		d3 = bfs(px2, py2);
		int ans = d1[px1][py1] + d1[px2][py2];
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				ans = min(ans, d1[i][j] + d2[i][j] + d3[i][j] - (A[i][j] == '#' ? 2 : 0));
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
