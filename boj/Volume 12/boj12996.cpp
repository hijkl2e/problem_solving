#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(3);
	for (int i = 0; i < 3; ++i) {
		cin >> A[i];
	}
	if (A[0] + A[1] + A[2] < N) {
		cout << "0\n";
		return 0;
	}
	vector<vector<ll>> nCr(N + 1, vector<ll>(N + 1));
	for (int i = 0; i <= N; ++i) {
		nCr[i][0] = nCr[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % MOD;
		}
	}
	ll ans{};
	for (int i = max({A[1] - A[0], N - A[0] - A[2], 0}); i <= A[1] && i <= N - A[0]; ++i) {
		ans += nCr[N][A[0]] * nCr[N - A[0]][i] % MOD * nCr[A[0]][A[1] - i] % MOD
				* nCr[A[0] + i][A[2] - (N - A[0] - i)] % MOD;
	}
	ans %= MOD;
	cout << ans << "\n";
	return 0;
}
