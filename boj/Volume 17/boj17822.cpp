#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, T{};
	cin >> N >> M >> T;
	vector<vector<int>> A(N + 2, vector<int>(M));
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	queue<ii> q;
	while (T--) {
		int x{}, d{}, k{};
		cin >> x >> d >> k;
		if (d == 0) {
			k = M - k;
		}
		for (int i = x; i <= N; i += x) {
			rotate(A[i].begin(), A[i].begin() + k, A[i].end());
		}
		for (int i = 1; i <= N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (A[i][j] == 0) {
					continue;
				} else if (A[i][j] == A[i + 1][j] || A[i][j] == A[i - 1][j]
						|| A[i][j] == A[i][(j + 1) % M] || A[i][j] == A[i][(j + M - 1) % M]) {
					q.push({i, j});
				}
			}
		}
		if (q.size()) {
			while (q.size()) {
				auto [x, y] = q.front(); q.pop();
				A[x][y] = 0;
			}
		} else {
			int sum{}, cnt{};
			for (int i = 1; i <= N; ++i) {
				sum += accumulate(A[i].begin(), A[i].end(), 0);
				cnt += M - count(A[i].begin(), A[i].end(), 0);
			}
			if (cnt == 0) {
				continue;
			}
			int x = sum / cnt;
			int y = (sum - 1) / cnt + 1;
			for (int i = 1; i <= N; ++i) {
				for (int j = 0; j < M; ++j) {
					if (A[i][j] > x) {
						--A[i][j];
					} else if (A[i][j] && A[i][j] < y) {
						++A[i][j];
					}
				}
			}
		}
	}
	int ans{};
	for (int i = 1; i <= N; ++i) {
		ans += accumulate(A[i].begin(), A[i].end(), 0);
	}
	cout << ans << "\n";
	return 0;
}
