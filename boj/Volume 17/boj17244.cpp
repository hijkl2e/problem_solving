#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N, M;
vector<string> A;

vector<vector<int>> bfs(int sx, int sy) {
	vector<vector<int>> D(N, vector<int>(M, -1));
	queue<ii> q;
	D[sx][sy] = 0;
	q.push({sx, sy});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] != '#' && D[nx][ny] == -1) {
				D[nx][ny] = D[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	return D;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> M >> N;
	cin.ignore();
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<ii> X;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == 'X') {
				X.push_back({i, j});
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == 'S') {
				X.insert(X.begin(), {i, j});
			} else if (A[i][j] == 'E') {
				X.push_back({i, j});
			}
		}
	}
	vector<vector<vector<int>>> D;
	for (auto &[x, y] : X) {
		D.push_back(bfs(x, y));
	}
	vector<int> B(X.size());
	for (int i = 0; i < B.size(); ++i) {
		B[i] = i;
	}
	int ans = 1e9;
	do {
		int cnt{};
		for (int i = 0; i < B.size() - 1; ++i) {
			auto &[x, y] = X[B[i + 1]];
			cnt += D[B[i]][x][y];
		}
		ans = min(ans, cnt);
	} while (next_permutation(B.begin() + 1, B.end() - 1));
	cout << ans << "\n";
	return 0;
}
