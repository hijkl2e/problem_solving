#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{1, 0, -1, 0};
const int dy[4]{0, 1, 0, -1};

int N, M, ans;
vector<vector<int>> A, C;
vector<ii> B;
vector<deque<bool>> vst;

void solve(int n) {
	if (n == B.size()) {
		for (int i = 0; i < N; ++i) {
			fill(vst[i].begin(), vst[i].end(), false);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (C[i][j] == 0) {
					continue;
				}
				auto [x, y] = B[i];
				while (0 <= x && x < N && 0 <= y && y < M && A[x][y] < 6) {
					vst[x][y] = true;
					x += dx[j];
					y += dy[j];
				}
			}
		}
		int cnt{};
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (A[i][j] < 6 && !vst[i][j]) {
					++cnt;
				}
			}
		}
		ans = min(ans, cnt);
		return;
	}
	for (int i = 0; i < 4; ++i) {
		solve(n + 1);
		rotate(C[n].begin(), C[n].begin() + 1, C[n].end());
	}
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
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == 0 || A[i][j] == 6) {
				continue;
			}
			B.push_back({i, j});
			C.push_back({1, A[i][j] > 2, A[i][j] == 2 || A[i][j] > 3, A[i][j] == 5});
		}
	}
	vst.assign(N, deque<bool>(M));
	ans = N * M;
	solve(0);
	cout << ans << "\n";
	return 0;
}
