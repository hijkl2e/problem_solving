#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(K);
	vector<int> B(K);
	for (int i = 0; i < K; ++i) {
		cin >> A[i] >> B[i];
	}
	vector<int> dp(N + 1);
	for (int i = 0; i < K; ++i) {
		for (int j = N; j >= B[i]; --j) {
			dp[j] = max(dp[j], dp[j - B[i]] + A[i]);
		}
	}
	cout << dp[N] << "\n";
	return 0;
}
