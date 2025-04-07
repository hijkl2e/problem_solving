#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e7 + 3;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> dp(100001);
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j < dp.size(); ++j) {
			if (dp[j] == 0) {
				continue;
			}
			int &val = dp[gcd(A[i], j)];
			val = (val + dp[j]) % MOD;
		}
		dp[A[i]] = (dp[A[i]] + 1) % MOD;
	}
	cout << dp[1] << "\n";
	return 0;
}
