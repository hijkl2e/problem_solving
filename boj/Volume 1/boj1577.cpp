#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using iiii = pair<ii, ii>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	set<iiii> S;
	while (K--) {
		ii p1, p2;
		cin >> p1.first >> p1.second;
		cin >> p2.first >> p2.second;
		S.insert({min(p1, p2), max(p1, p2)});
	}
	vector<vector<ll>> dp(N + 1, vector<ll>(M + 1));
	dp[0][0] = 1;
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= M; ++j) {
			if (i + 1 <= N && S.find({{i, j}, {i + 1, j}}) == S.end()) {
				dp[i + 1][j] += dp[i][j];
			}
			if (j + 1 <= M && S.find({{i, j}, {i, j + 1}}) == S.end()) {
				dp[i][j + 1] += dp[i][j];
			}
		}
	}
	cout << dp[N][M] << "\n";
	return 0;
}
