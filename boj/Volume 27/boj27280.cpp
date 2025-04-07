#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> H(N + 1);
	vector<int> S(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> H[i] >> S[i];
	}
	vector<vector<ll>> A(N + 1, vector<ll>(N + 1));
	for (int i = 1; i <= N; ++i) {
		ll x{}, y{};
		for (int j = i; j <= N; ++j) {
			if (x < H[j]) {
				x = H[j];
				y = S[j];
			} else if (x == H[j]) {
				y += S[j];
			}
			A[i][j] = y;
		}
	}
	vector<vector<ll>> dp(M + 1, vector<ll>(N + 1, -INF));
	dp[0][0] = 0;
	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= N; ++j) {
			for (int k = 0; k < j; ++k) {
				dp[i][j] = max(dp[i][j], dp[i - 1][k] + A[k + 1][j]);
			}
		}
	}
	cout << dp[M][N] << "\n";
	return 0;
}
