#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int C{}, N{};
	cin >> C >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
	}
	vector<int> dp(C + 100, INF);
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j + B[i] < dp.size(); ++j) {
			dp[j + B[i]] = min(dp[j + B[i]], dp[j] + A[i]);
		}
	}
	int ans = *min_element(dp.begin() + C, dp.end());
	cout << ans << "\n";
	return 0;
}
