#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{}, x{};
	cin >> N >> K >> x;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
	}
	vector<bitset<16001>> dp(81);
	dp[0][0] = true;
	for (int i = 0; i < N; ++i) {
		for (int j = min(i + 1, K); j > 0; --j) {
			dp[j] |= dp[j - 1] << A[i];
		}
	}
	int ans{};
	for (int i = 0; i <= K * x; ++i) {
		if (dp[K][i]) {
			ans = max(ans, i * (K * x - i));
		}
	}
	cout << ans << "\n";
	return 0;
}
