#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 5e8;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N, M, X;
vector<vector<int>> A;
vector<ii> B(4);
vector<ii> C(4);

void dfs(int x, int y, int z, int w, int s, bool f) {
	B[z - 1] = {x, y};
	if (z == 4) {
		if (X < w) {
			X = w;
			if (f) {
				copy(B.begin(), B.end(), C.begin());
			}
		}
		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (i == s) {
			continue;
		}
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (A[nx][ny]) {
			dfs(nx, ny, z + 1, w + A[nx][ny], i ^ 1, f);
		}
	}
}

void solve(int x, int y, int w) {
	bool f = w == 0;
	w += A[x][y];
	dfs(x, y, 1, w, -1, f);
	int minv = INF, mini{};
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		w += A[nx][ny];
		if (minv > A[nx][ny]) {
			minv = A[nx][ny];
			mini = i;
		}
		B[i] = {nx, ny};
	}
	B[mini] = {x, y};
	if (X < w - minv) {
		X = w - minv;
		if (f) {
			copy(B.begin(), B.end(), C.begin());
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	A.assign(N + 2, vector<int>(M + 2));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> A[i][j];
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			solve(i, j, 0);
		}
	}
	int z = X;
	for (auto &[r, c] : C) {
		A[r][c] -= INF;
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			solve(i, j, z);
		}
	}
	for (auto &[r, c] : C) {
		A[r][c] += INF;
	}
	auto [x, y] = C[0];
	vector<ii> D;
	for (int i = -7; i < 8; ++i) {
		for (int j = -7; j < 8; ++j) {
			if (abs(i) + abs(j) < 8 && 1 <= x + i && x + i <= N
					&& 1 <= y + j && y + j <= M) {
				D.push_back({x + i, y + j});
			}
		}
	}
	int ans = X;
	for (auto &[x1, y1] : D) {
		X = 0;
		solve(x1, y1, 0);
		int z = X;
		for (auto &[r, c] : C) {
			A[r][c] -= INF;
		}
		for (auto &[x2, y2] : D) {
			solve(x2, y2, z);
		}
		for (auto &[r, c] : C) {
			A[r][c] += INF;
		}
		ans = max(ans, X);
	}
	cout << ans << "\n";
	return 0;
}
