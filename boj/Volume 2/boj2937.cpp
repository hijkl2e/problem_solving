#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N + 1, vector<int>(N + 1));
	for (int i = 0; i < M; ++i) {
		int r{}, c{};
		cin >> r >> c;
		A[r][c] = 1;
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			A[i][j] += A[i][j - 1] + A[i - 1][j] - A[i - 1][j - 1];
		}
	}
	int ans{};
	for (int k = 1; k <= M; ++k) {
		if (M % k) {
			continue;
		}
		int l = M / k;
		for (int i = k; i <= N; ++i) {
			for (int j = l; j <= N; ++j) {
				ans = max(ans, A[i][j] - A[i - k][j] - A[i][j - l] + A[i - k][j - l]);
			}
		}
	}
	ans = M - ans;
	cout << ans << "\n";
	return 0;
}
