#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;
const int dx[8]{-1, 1, 0, 0, -1, -1, 1, 1};
const int dy[8]{0, 0, -1, 1, -1, 1, -1, 1};

ll dp[2][100][100][100];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	cin.ignore();
	vector<string> S(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, S[i]);
	}
	int rs{}, cs{}, re{}, ce{};
	cin >> rs >> cs >> re >> ce;
	--rs, --cs, --re, --ce;
	for (int i = 0; i < 8; ++i) {
		int r = rs + dx[i];
		int c = cs + dy[i];
		while (0 <= r && r < N && 0 <= c && c < M && S[r][c] == '.') {
			dp[0][i][r][c] = 1;
			r += dx[i];
			c += dy[i];
		}
	}
	for (int i = 0; i < K - 1; ++i) {
		memset(dp[1], 0, sizeof dp[1]);
		for (int j = 0; j < 8; ++j) {
			for (int k = 0; k < N; ++k) {
				for (int l = 0; l < M; ++l) {
					int r = k - dx[j];
					int c = l - dy[j];
					if (0 <= r && r < N && 0 <= c && c < M && S[r][c] == '.') {
						continue;
					}
					r = k, c = l;
					ll sum{};
					while (0 <= r && r < N && 0 <= c && c < M && S[r][c] == '.') {
						dp[1][j][r][c] = (dp[1][j][r][c] + sum) % MOD;
						for (int m = 0; m < 8; ++m) {
							if (j == m) {
								continue;
							}
							sum = (sum + dp[0][m][r][c]) % MOD;
						}
						r += dx[j];
						c += dy[j];
					}
				}
			}
		}
		memcpy(dp[0], dp[1], sizeof dp[1]);
	}
	ll ans{};
	for (int i = 0; i < 8; ++i) {
		ans = (ans + dp[0][i][re][ce]) % MOD;
	}
	cout << ans << "\n";
	return 0;
}
