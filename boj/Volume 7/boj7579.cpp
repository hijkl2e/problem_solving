#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	vector<int> dp(10001, -INF);
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = dp.size() - 1; j >= B[i]; --j) {
			dp[j] = max(dp[j], dp[j - B[i]] + A[i]);
		}
	}
	int ans{};
	while (dp[ans] < M) {
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
