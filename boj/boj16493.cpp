#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(M);
	vector<int> B(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i] >> B[i];
	}
	vector<int> dp(N + 1);
	for (int i = 0; i < M; ++i) {
		for (int j = N; j >= A[i]; --j) {
			dp[j] = max(dp[j], dp[j - A[i]] + B[i]);
		}
	}
	cout << dp[N] << "\n";
	return 0;
}
