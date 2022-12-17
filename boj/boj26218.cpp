#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, B{};
	cin >> N >> B;
	vector<int> P(N + 1);
	vector<int> A(N + 1);
	vector<int> C(N + 1);
	for (int i = N; i > 0; --i) {
		cin >> P[i] >> A[i] >> C[i];
	}
	vector<vector<ll>> dp(N + 1, vector<ll>(B + 1));
	vector<vector<int>> dp2(N + 1, vector<int>(B + 1));
	fill(dp[0].begin(), dp[0].end(), 1);
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= B; ++j) {
			for (int k = 0; k * C[i] <= j; ++k) {
				int p = min(P[i] + k * A[i], 100);
				ll val = dp[i - 1][j - k * C[i]] * p;
				if (dp[i][j] < val) {
					dp[i][j] = val;
					dp2[i][j] = k;
				}
				if (p == 100) {
					break;
				}
			}
		}
	}
	cout << dp[N][B] << "\n";
	for (int i = N; i > 0; --i) {
		cout << dp2[i][B] << (i == 1 ? "\n" : " ");
		B -= dp2[i][B] * C[i];
	}
	return 0;
}
