#include <bits/stdc++.h>

using namespace std;

int A[501];
int psum[501];
int dp[501][502];
int opt[501][502];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 1; i < 501; ++i) {
		opt[i][i + 1] = i;
	}
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		for (int i = 1; i <= N; ++i) {
			cin >> A[i];
		}
		partial_sum(begin(A), end(A), begin(psum));
		memset(dp, 0x3f, sizeof dp);
		for (int i = 1; i <= N; ++i) {
			dp[i][i + 1] = 0;
		}
		for (int i = N - 1; i > 0; --i) {
			for (int j = i + 2; j < N + 2; ++j) {
				for (int k = opt[i][j - 1]; k <= opt[i + 1][j]; ++k) {
					int val = dp[i][k] + dp[k][j];
					if (dp[i][j] > val) {
						dp[i][j] = val;
						opt[i][j] = k;
					}
				}
				dp[i][j] += psum[j - 1] - psum[i - 1];
			}
		}
		cout << dp[1][N + 1] << "\n";
	}
	return 0;
}
