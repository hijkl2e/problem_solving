#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> nCr(53, vector<int>(53));
	for (int i = 0; i < 53; ++i) {
		nCr[i][0] = nCr[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % MOD;
		}
	}
	int ans{};
	for (int i = 1; 4 * i <= N; ++i) {
		ans += (i % 2 ? 1 : -1) * nCr[13][i] * nCr[52 - 4 * i][N - 4 * i] % MOD;
	}
	ans = (ans % MOD + MOD) % MOD;
	cout << ans << "\n";
	return 0;
}
