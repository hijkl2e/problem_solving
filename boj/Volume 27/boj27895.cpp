#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const ll MOD = 1e9 + 7;

ll dp[2][2001][2001];
ii P[2001][2001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> M >> N >> K;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	memset(P, -1, sizeof P);
	while (K--) {
		int x1{}, y1{}, x2{}, y2{};
		cin >> y1 >> x1 >> y2 >> x2;
		P[x1][y1] = {x2, y2};
		P[x2][y2] = {x1, y1};
	}
	dp[0][0][0] = 1;
	for (int k = 0; k < 2; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (j < M - 1 && A[i][j + 1] != '1') {
					dp[k][i][j + 1] = (dp[k][i][j + 1] + dp[k][i][j]) % MOD;
				}
				if (i < N - 1 && A[i + 1][j] != '1') {
					dp[k][i + 1][j] = (dp[k][i + 1][j] + dp[k][i][j]) % MOD;
				}
				if (k == 0 && A[i][j] == 'P') {
					auto &[x, y] = P[i][j];
					if (!((x == i && y == j + 1) || (x == i + 1 && y == j))) {
						dp[1][x][y] = (dp[1][x][y] + dp[0][i][j]) % MOD;
					}
				}
			}
		}
	}
	ll ans = (dp[0][N - 1][M - 1] + dp[1][N - 1][M - 1]) % MOD;
	cout << ans << "\n";
	return 0;
}
