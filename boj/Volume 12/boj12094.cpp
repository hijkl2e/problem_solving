#include <bits/stdc++.h>

using namespace std;

int N, ans;
vector<vector<int>> A[12];

void rotate(int z) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			A[11][i][j] = A[z][N - j - 1][i];
		}
	}
	swap(A[z], A[11]);
}

void dfs(int z, int y, bool f) {
	ans = max(ans, y);
	if ((y << (10 - z)) <= ans) {
		return;
	}
	auto &v = A[z + 1];
	for (int d = 0; d < 4; ++d) {
		if (!f && d % 2 == 0) {
			rotate(z);
			continue;
		}
		for (int i = 0; i < N; ++i) {
			fill(v[i].begin(), v[i].end(), 0);
		}
		int maxv = y;
		bool f1{}, f2{};
		for (int i = 0; i < N; ++i) {
			for (int j = 0, k = 0; j < N; ++j) {
				int x = A[z][i][j];
				if (x == 0) {
					continue;
				}
				if (v[i][k]) {
					if (v[i][k] == x) {
						v[i][k++] *= 2;
						maxv = max(maxv, 2 * x);
						f1 = true;
					} else {
						v[i][++k] = x;
					}
				} else {
					v[i][k] = x;
				}
				f2 |= k < j;
			}
		}
		if (f1 || f2) {
			dfs(z + 1, maxv, f1);
		}
		rotate(z);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for (int i = 0; i < 12; ++i) {
		A[i].assign(N, vector<int>(N));
	}
	auto &v = A[0];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> v[i][j];
		}
	}
	int maxv{};
	for (int i = 0; i < N; ++i) {
		maxv = max(maxv, *max_element(v[i].begin(), v[i].end()));
	}
	dfs(0, maxv, true);
	cout << ans << "\n";
	return 0;
}
