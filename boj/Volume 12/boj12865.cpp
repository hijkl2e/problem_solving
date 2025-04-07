#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
	}
	vector<int> dp(K + 1);
	for (int i = 0; i < N; ++i) {
		for (int j = K; j >= A[i]; --j) {
			dp[j] = max(dp[j], dp[j - A[i]] + B[i]);
		}
	}
	int ans = *max_element(dp.begin(), dp.end());
	cout << ans << "\n";
	return 0;
}
