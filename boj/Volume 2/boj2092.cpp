#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e6;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, X{}, Y{};
	cin >> N >> M >> X >> Y;
	vector<int> A(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
	}
	vector<int> B(N + 1);
	for (int i = 0; i < M; ++i) {
		++B[A[i]];
	}
	vector<int> dp(M + 1);
	dp[0] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = M; j >= 0; --j) {
			for (int k = 1; k <= B[i] && j + k <= M; ++k) {
				dp[j + k] = (dp[j + k] + dp[j]) % MOD;
			}
		}
	}
	int ans = accumulate(dp.begin() + X, dp.begin() + Y + 1, 0LL) % MOD;
	cout << ans << "\n";
	return 0;
}
