#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<int>> B(N + 1);
	for (int i = 0; i < (1 << N); ++i) {
		int x = __builtin_popcount(i);
		B[x].push_back(i);
	}
	vector<double> dp(1 << N);
	dp[0] = 100;
	for (int i = 0; i < N; ++i) {
		for (int x : B[i]) {
			for (int j = 0; j < N; ++j) {
				if (x & (1 << j)) {
					continue;
				}
				int y = x | (1 << j);
				dp[y] = max(dp[y], dp[x] * A[i][j] / 100);
			}
		}
	}
	cout << fixed << setprecision(10);
	cout << dp.back() << "\n";
	return 0;
}
