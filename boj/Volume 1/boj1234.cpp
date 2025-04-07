#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll dp[11][101][101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, a{}, b{}, c{};
	cin >> N >> a >> b >> c;
	if (a + b + c < N * (N + 1) / 2) {
		cout << "0\n";
		return 0;
	}
	vector<int> fact(N + 1);
	fact[0] = 1;
	for (int i = 1; i <= N; ++i) {
		fact[i] = i * fact[i - 1];
	}
	dp[0][a][b][c] = 1;
	vector<int> A(3);
	for (int i = 1; i <= N; ++i) {
		for (A[0] = 0; A[0] <= a; ++A[0]) {
			for (A[1] = 0; A[1] <= b; ++A[1]) {
				for (A[2] = 0; A[2] <= c; ++A[2]) {
					ll val = dp[i - 1][A[0]][A[1]][A[2]];
					if (val == 0) {
						continue;
					}
					for (int j = 0; j < 3; ++j) {
						if (A[j] >= i) {
							A[j] -= i;
							dp[i][A[0]][A[1]][A[2]] += val;
							A[j] += i;
						}
					}
					if (i % 2 == 0) {
						int x = i / 2;
						for (int j = 0; j < 3; ++j) {
							A[j] += x;
							if (min({A[0], A[1], A[2]}) >= x) {
								dp[i][A[0] - x][A[1] - x][A[2] - x]
										+= fact[i] / fact[x] / fact[x] * val;
							}
							A[j] -= x;
						}
					}
					if (i % 3 == 0 && min({A[0], A[1], A[2]}) >= i / 3) {
						int x = i / 3;
						dp[i][A[0] - x][A[1] - x][A[2] - x]
								+= fact[i] / fact[x] / fact[x] / fact[x] * val;
					}
				}
			}
		}
	}
	ll ans{};
	for (int i = 0; i <= a; ++i) {
		for (int j = 0; j <= b; ++j) {
			for (int k = 0; k <= c; ++k) {
				ans += dp[N][i][j][k];
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
