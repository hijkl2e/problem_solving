#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N, M, ans;
vector<vector<int>> A, B;
vector<deque<bool>> C;

ii bfs(int sx, int sy, bool del) {
	for (int i = 0; i < N; ++i) {
		fill(C[i].begin(), C[i].end(), false);
	}
	int s = A[sx][sy];
	int c1{}, c2{};
	queue<ii> q;
	C[sx][sy] = true;
	q.push({sx, sy});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < N && (A[nx][ny] == 0 || A[nx][ny] == s)
					&& (A[nx][ny] == 0 || sx < nx || (sx == nx && sy < ny)) && !C[nx][ny]) {
				C[nx][ny] = true;
				q.push({nx, ny});
			}
		}
		if (A[x][y]) {
			++c1;
		} else {
			++c2;
		}
		if (del) {
			A[x][y] = -2;
		}
	}
	if (del) {
		ans += (c1 + c2) * (c1 + c2);
	}
	return {c1, c2};
}

void gravity() {
	for (int j = 0; j < N; ++j) {
		for (int i = N - 1, k = N - 1; i >= 0; --i) {
			if (A[i][j] >= 0) {
				int b = A[i][j];
				A[i][j] = -2;
				A[k--][j] = b;
			} else if (A[i][j] == -1) {
				k = i - 1;
			}
		}
	}
}

void rotate() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			B[i][j] = A[j][N - i - 1];
		}
	}
	swap(A, B);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	A.assign(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	B.assign(N, vector<int>(N));
	C.assign(N, deque<bool>(N));
	while (true) {
		int x{}, y{}, c1{}, c2{};
		for (int i = N - 1; i >= 0; --i) {
			for (int j = N - 1; j >= 0; --j) {
				if (A[i][j] < 1) {
					continue;
				}
				auto [d1, d2] = bfs(i, j, false);
				if (c1 + c2 < d1 + d2 || (c1 + c2 == d1 + d2 && c2 < d2)) {
					x = i, y = j;
					c1 = d1, c2 = d2;
				}
			}
		}
		if (c1 + c2 < 2) {
			break;
		}
		bfs(x, y, true);
		gravity();
		rotate();
		gravity();
	}
	cout << ans << "\n";
	return 0;
}
