#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

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
	vector<int> dp(1 << N, INF);
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < (1 << N); ++j) {
			if (__builtin_popcount(j) != i) {
				continue;
			}
			for (int k = 0; k < N; ++k) {
				if (j & (1 << k)) {
					continue;
				}
				int &val = dp[j | (1 << k)];
				val = min(val, dp[j] + A[i][k]);
			}
		}
	}
	cout << dp.back() << "\n";
	return 0;
}
