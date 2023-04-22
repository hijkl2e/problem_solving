#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e8;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N, M;
vector<string> A;
vector<ii> B;

vector<int> bfs(int sx, int sy) {
	vector<vector<int>> D(N, vector<int>(M, INF));
	queue<ii> q;
	D[sx][sy] = 0;
	q.push({sx, sy});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] != 'x' && D[nx][ny] == INF) {
				D[nx][ny] = D[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	vector<int> ret;
	for (auto &[x, y] : B) {
		ret.push_back(D[x][y]);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin >> M >> N, N) {
		cin.ignore();
		A.resize(N);
		for (int i = 0; i < N; ++i) {
			getline(cin, A[i]);
		}
		int sx{}, sy{};
		B.clear();
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (A[i][j] == 'o') {
					sx = i, sy = j;
				} else if (A[i][j] == '*') {
					B.push_back({i, j});
				}
			}
		}
		vector<vector<int>> C;
		for (auto &[x, y] : B) {
			C.push_back(bfs(x, y));
		}
		C.push_back(bfs(sx, sy));
		vector<int> D(C.size());
		D[0] = C.size() - 1;
		for (int i = 1; i < D.size(); ++i) {
			D[i] = i - 1;
		}
		int ans = INF;
		do {
			int sum{};
			for (int i = 0; i < B.size(); ++i) {
				sum += C[D[i]][D[i + 1]];
			}
			ans = min(ans, sum);
		} while (next_permutation(D.begin() + 1, D.end()));
		cout << (ans == INF ? -1 : ans) << "\n";
	}
	return 0;
}
