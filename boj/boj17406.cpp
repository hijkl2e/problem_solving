#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const int dx[4]{1, 0, -1, 0};
const int dy[4]{0, 1, 0, -1};

int N, M, K, ans;
vector<vector<int>> A;
vector<iii> B;
deque<bool> C;

void rotate(int r, int c, int s, bool rev) {
	while (s) {
		vector<int> D;
		int x = r - s;
		int y = c - s;
		for (int d = 0; d < 4;) {
			D.push_back(A[x][y]);
			x += dx[d];
			y += dy[d];
			if ((x == r - s || x == r + s) && (y == c - s || y == c + s)) {
				++d;
			}
		}
		rotate(D.begin(), rev ? (D.end() - 1) : (D.begin() + 1), D.end());
		for (int d = 0, i = 0; d < 4; ++i) {
			A[x][y] = D[i];
			x += dx[d];
			y += dy[d];
			if ((x == r - s || x == r + s) && (y == c - s || y == c + s)) {
				++d;
			}
		}
		--s;
	}
}

void solve(int n) {
	if (n == K) {
		for (int i = 0; i < N; ++i) {
			ans = min(ans, accumulate(A[i].begin(), A[i].end(), 0));
		}
		return;
	}
	for (int i = 0; i < K; ++i) {
		if (C[i]) {
			continue;
		}
		auto &[r, c, s] = B[i];
		C[i] = true;
		rotate(r, c, s, false);
		solve(n + 1);
		rotate(r, c, s, true);
		C[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> K;
	A.assign(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	B.resize(K);
	for (auto &[r, c, s] : B) {
		cin >> r >> c >> s;
		--r, --c;
	}
	C.resize(K);
	ans = 1e9;
	solve(0);
	cout << ans << "\n";
	return 0;
}
