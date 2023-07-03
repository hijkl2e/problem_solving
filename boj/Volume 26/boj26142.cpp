#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A.begin(), A.end());
	vector<vector<ll>> dp(2, vector<ll>(N + 1, -INF));
	vector<ll> ans(N + 1);
	dp[1][0] = 0;
	for (int i = 0; i < N; ++i) {
		copy(dp[1].begin(), dp[1].end(), dp[0].begin());
		dp[1][0] = 0;
		for (int j = 0; j < N; ++j) {
			if (dp[0][j] == -INF) {
				continue;
			}
			dp[1][j + 1] = max(dp[1][j + 1], dp[0][j] + j * A[i].first + A[i].second);
		}
		for (int j = 1; j <= N; ++j) {
			ans[j] = max(ans[j], dp[1][j]);
		}
	}
	for (int i = 1; i <= N; ++i) {
		cout << ans[i] << "\n";
	}
	return 0;
}
