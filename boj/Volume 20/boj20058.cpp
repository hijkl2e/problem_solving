#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N;
vector<vector<int>> A, B;

void rotate(int x, int y, int L) {
	for (int i = 0; i < L; ++i) {
		for (int j = 0; j < L; ++j) {
			B[i][j] = A[x + i][y + j];
		}
	}
	for (int i = 0; i < L; ++i) {
		for (int j = 0; j < L; ++j) {
			A[x + i][y + j] = B[L - j - 1][i];
		}
	}
}

int bfs(int sx, int sy) {
	int ret{};
	queue<ii> q;
	A[sx][sy] = 0;
	q.push({sx, sy});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < N && A[nx][ny]) {
				A[nx][ny] = 0;
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
	int Q{};
	cin >> N >> Q;
	N = 1 << N;
	A.assign(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	B.assign(N, vector<int>(N));
	while (Q--) {
		int L{};
		cin >> L;
		L = 1 << L;
		for (int i = 0; i < N; i += L) {
			for (int j = 0; j < N; j += L) {
				rotate(i, j, L);
			}
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				int cnt{};
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (0 <= nx && nx < N && 0 <= ny && ny < N && A[nx][ny]) {
						++cnt;
					}
				}
				B[i][j] = max(A[i][j] - (cnt < 3), 0);
			}
		}
		swap(A, B);
	}
	int sum{}, maxv{};
	for (int i = 0; i < N; ++i) {
		sum += accumulate(A[i].begin(), A[i].end(), 0);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j]) {
				maxv = max(maxv, bfs(i, j));
			}
		}
	}
	cout << sum << "\n" << maxv << "\n";
	return 0;
}
