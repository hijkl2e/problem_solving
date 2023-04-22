#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int N, M, D;

int solve(vector<vector<int>> A, const vector<int> &B) {
	int ret{};
	vector<ii> C(3);
	for (int l = 0; l < N; ++l) {
		fill(C.begin(), C.end(), make_pair(-1, -1));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (A[i][j] == 0) {
					continue;
				}
				for (int k = 0; k < 3; ++k) {
					int nd = (N - i) + abs(B[k] - j);
					if (nd > D) {
						continue;
					} else if (C[k].first == -1) {
						C[k] = {i, j};
						continue;
					}
					int d = (N - C[k].first) + abs(B[k] - C[k].second);
					if (nd < d || (nd == d && j < C[k].second)) {
						C[k] = {i, j};
					}
				}
			}
		}
		for (auto &[x, y] : C) {
			if (x == -1 || A[x][y] == 0) {
				continue;
			}
			A[x][y] = 0;
			++ret;
		}
		rotate(A.begin(), A.end() - 1, A.end());
		fill(A[0].begin(), A[0].end(), 0);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> D;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	int ans{};
	for (int i = 0; i < M; ++i) {
		for (int j = i + 1; j < M; ++j) {
			for (int k = j + 1; k < M; ++k) {
				ans = max(ans, solve(A, {i, j, k}));
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
