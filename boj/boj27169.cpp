#include <bits/stdc++.h>

using namespace std;

double dp[2][101][101];
int cnt[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> hp(2);
	vector<int> atk(2);
	vector<int> def(2);
	vector<int> evd(2);
	for (int i = 0; i < 2; ++i) {
		cin >> hp[i] >> atk[i] >> def[i] >> evd[i];
	}
	for (int i = 1; i <= hp[0]; ++i) {
		dp[1][i][0] = cnt[i][0] = 36;
	}
	for (int i = 1; i <= hp[0]; ++i) {
		for (int j = 1; j <= hp[1]; ++j) {
			int sum{};
			for (int k = 0; k < 2; ++k) {
				for (int d1 = 1; d1 < 7; ++d1) {
					int a = max(1, d1 + atk[k ^ 1]);
					for (int d2 = 1; d2 < 7; ++d2) {
						int x = k ? j : i;
						if (x <= max(1, a - (6 + def[k])) || a < max(1, 1 + evd[k])
								|| (a < x && a < max(1, 3 + evd[k]))) {
							if (max(1, d2 + evd[k]) <= a) {
								x -= a;
							}
						} else {
							x -= max(1, a - max(1, d2 + def[k]));
						}
						x = max(x, 0);
						if (k) {
							dp[0][i][j] += dp[1][i][x];
							sum += cnt[i][x];
							if (x != j) {
								dp[0][i][j] += dp[0][i][x] * (36 - cnt[i][x]);
								sum += 36 - cnt[i][x];
							}
						} else {
							if (x != i) {
								dp[1][i][j] += dp[0][x][j];
								++cnt[i][j];
							}
						}
					}
				}
			}
			dp[0][i][j] /= sum;
		}
	}
	cout << fixed << setprecision(10);
	cout << dp[0][hp[0]][hp[1]] << "\n";
	return 0;
}
