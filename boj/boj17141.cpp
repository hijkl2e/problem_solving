#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N, ans;
vector<vector<int>> A;

int solve() {
	vector<vector<int>> D(N, vector<int>(N, INF));
	queue<ii> q;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] == 2) {
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
			if (0 <= nx && nx < N && 0 <= ny && ny < N && A[nx][ny] == 0 && D[nx][ny] == INF) {
				D[nx][ny] = D[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	int ret{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] == 0) {
				ret = max(ret, D[i][j]);
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{};
	cin >> N >> M;
	A.assign(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	vector<ii> B;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] == 2) {
				B.push_back({i, j});
				A[i][j] = 0;
			}
		}
	}
	ans = INF;
	for (int i = 0; i < (1 << B.size()); ++i) {
		if (__builtin_popcount(i) != M) {
			continue;
		}
		for (int j = 0; j < B.size(); ++j) {
			if (i & (1 << j)) {
				auto &[x, y] = B[j];
				A[x][y] = 2;
			}
		}
		ans = min(ans, solve());
		for (int j = 0; j < B.size(); ++j) {
			if (i & (1 << j)) {
				auto &[x, y] = B[j];
				A[x][y] = 0;
			}
		}
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
