#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<vector<int>> B(N + 1);
	for (int i = 1; i < (1 << N); ++i) {
		B[__builtin_popcount(i)].push_back(i);
	}
	vector<int> dp(1 << N, INF);
	dp.back() = 0;
	for (int i = N; i > 0; --i) {
		for (int x : B[i]) {
			if (dp[x] == INF) {
				continue;
			} else if (i == 1) {
				dp[0] = min(dp[0], dp[x] + A[__builtin_ctz(x)]);
				continue;
			}
			for (int j = 0; j < N; ++j) {
				if ((x & (1 << j)) == 0) {
					continue;
				}
				for (int k = j + 1; k < N; ++k) {
					if ((x & (1 << k)) == 0 || A[j] == A[k]) {
						continue;
					} else if (i == 2) {
						dp[0] = min(dp[0], dp[x] + max(A[j], A[k]));
						continue;
					}
					int y = x & ~((1 << j) | (1 << k));
					for (int l = 0; l < N; ++l) {
						if (y & (1 << l)) {
							continue;
						}
						int z = y | (1 << l);
						dp[z] = min(dp[z], dp[x] + max(A[j], A[k]) + A[l]);
					}
				}
			}
		}
	}
	cout << (dp[0] == INF ? -1 : dp[0]) << "\n";
	return 0;
}
