#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> dp(K + 1);
	dp[0] = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = A[i]; j <= K; ++j) {
			dp[j] += dp[j - A[i]];
		}
	}
	cout << dp[K] << "\n";
	return 0;
}
