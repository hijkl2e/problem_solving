#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N, M;
vector<vector<int>> A;
vector<deque<bool>> vst;

int bfs(int sx, int sy) {
	for (int i = 0; i < N; ++i) {
		fill(vst[i].begin(), vst[i].end(), false);
	}
	queue<ii> q;
	vst[sx][sy] = true;
	q.push({sx, sy});
	int ret{};
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (A[nx][ny] && !vst[nx][ny]) {
				vst[nx][ny] = true;
				q.push({nx, ny});
			}
		}
		++ret;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	A.assign(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	int cnt{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j]) {
				++cnt;
			}
		}
	}
	vector<vector<int>> B(N, vector<int>(M));
	vst.assign(N, deque<bool>(M));
	int ans{};
	for (int t = 1;; ++t) {
		for (int i = 0; i < N; ++i) {
			copy(A[i].begin(), A[i].end(), B[i].begin());
		}
		for (int i = 1; i < N - 1; ++i) {
			for (int j = 1; j < M - 1; ++j) {
				if (A[i][j] == 0) {
					continue;
				}
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (A[nx][ny] == 0 && --B[i][j] == 0) {
						--cnt;
						break;
					}
				}
			}
		}
		if (cnt == 0) {
			break;
		}
		swap(A, B);
		int res{};
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (A[i][j]) {
					res = bfs(i, j);
					i = N;
					break;
				}
			}
		}
		if (res < cnt) {
			ans = t;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
