#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e9 + 7;

int N;
vector<vector<ll>> A;

ll solve() {
	vector<vector<ll>> dp(N + 1, vector<ll>(N + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + A[i][j];
		}
	}
	return dp[N][N];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.assign(N + 1, vector<ll>(N + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> A[i][j];
		}
	}
	int P{};
	cin >> P;
	for (int i = 0; i < P; ++i) {
		int r{}, c{};
		cin >> r >> c;
		A[r][c] += INF;
	}
	ll ans = max(solve() - P * INF, -1LL);
	cout << ans << "\n";
	return 0;
}
