#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 0x3f3f3f3f3f3f3f3f;

ll dp[2][2][5001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, a{}, b{}, x{}, y{};
	cin >> N >> a >> b >> x >> y;
	vector<ll> T(N + 1);
	vector<ll> S(N + 1);
	T[0] = -INF;
	for (int i = 1; i <= N; ++i) {
		cin >> T[i] >> S[i];
	}
	memset(dp, 0x3f, sizeof dp);
	dp[1][0][0] = 0;
	for (int i = 1; i <= N; ++i) {
		memcpy(dp[0], dp[1], sizeof dp[1]);
		memset(dp[1], 0x3f, sizeof dp[1]);
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < i; ++k) {
				if (dp[0][j][k] == INF) {
					continue;
				}
				int p1 = j ? k : (i - 1);
				int p2 = j ? (i - 1) : k;
				if ((S[i] & 1) && T[i] - T[p1] >= a) {
					dp[1][0][p2] = min(dp[1][0][p2], dp[0][j][k] + x);
				}
				if ((S[i] & 2) && T[i] - T[p2] >= b) {
					dp[1][1][p1] = min(dp[1][1][p1], dp[0][j][k] + y);
				}
			}
		}
	}
	ll ans = INF;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < N; ++j) {
			ans = min(ans, dp[1][i][j]);
		}
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
