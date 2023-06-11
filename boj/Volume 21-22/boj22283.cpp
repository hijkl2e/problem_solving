#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, M{}, K{}, R{};
	cin >> N >> M >> K >> R;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(N);
	vector<int> C(N);
	for (int i = 0; i < N - 1; ++i) {
		cin >> B[i] >> C[i];
	}
	vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, INF));
	dp[0][1] = 0;
	for (int i = 0; i < N; ++i) {
		copy(dp[i].begin(), dp[i].end(), dp[i + 1].begin());
		for (int j = 1; j <= M; ++j) {
			for (int k = 1; j + k <= M && K * k <= A[i]; ++k) {
				dp[i + 1][j + k] = min(dp[i + 1][j + k], dp[i][j] + R * k);
			}
			for (int k = 1; j - k > 0 && K * k <= A[i]; ++k) {
				dp[i + 1][j - k] = min(dp[i + 1][j - k], dp[i][j] + R * k);
			}
		}
		for (int j = 1; j <= M; ++j) {
			dp[i + 1][j] += C[i] * j;
		}
	}
	ll ans = accumulate(A.begin(), A.end(), 0) + accumulate(B.begin(), B.end(), 0) + dp[N][1];
	cout << ans << "\n";
	return 0;
}
