#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, T{};
	cin >> N >> T;
	vector<int> K(N);
	vector<int> S(N);
	for (int i = 0; i < N; ++i) {
		cin >> K[i] >> S[i];
	}
	vector<int> dp(T + 1, -INF);
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = T; j >= K[i]; --j) {
			dp[j] = max(dp[j], dp[j - K[i]] + S[i]);
		}
	}
	int ans = *max_element(dp.begin(), dp.end());
	cout << ans << "\n";
	return 0;
}
