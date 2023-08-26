#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{}, K{};
	cin >> T >> K;
	vector<int> A(K);
	vector<int> B(K);
	for (int i = 0; i < K; ++i) {
		cin >> A[i] >> B[i];
	}
	vector<int> dp(T + 1);
	dp[0] = 1;
	for (int i = 0; i < K; ++i) {
		for (int j = T; j >= A[i]; --j) {
			for (int k = 1; k <= B[i] && j >= k * A[i]; ++k) {
				dp[j] += dp[j - k * A[i]];
			}
		}
	}
	cout << dp[T] << "\n";
	return 0;
}
