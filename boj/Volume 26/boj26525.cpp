#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int N, X, K;
vector<string> A;
vector<ll> fact;

ll pow(ll x, ll y) {
	ll ret = 1;
	while (y) {
		if (y % 2) {
			ret = ret * x % MOD;
		}
		x = x * x % MOD;
		y /= 2;
	}
	return ret;
}

ll solve(int a, int b, int c, int d) {
	int cnt{};
	for (int i = 0; i < N; ++i) {
		cnt += '1' - A[a * i + b][c * i + d];
	}
	return K < cnt ? 0 : (fact[N * N] * pow(fact[X], MOD - 2) % MOD * fact[X - cnt] % MOD
						* fact[K] % MOD * pow(fact[K - cnt], MOD - 2) % MOD);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K;
	cin.ignore();
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			X += '1' - A[i][j];
		}
	}
	fact.resize(N * N + 1);
	fact[0] = 1;
	for (int i = 1; i < fact.size(); ++i) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	ll ans = solve(1, 0, 1, 0) + solve(1, 0, -1, N - 1);
	for (int i = 0; i < N; ++i) {
		ans += solve(0, i, 1, 0) + solve(1, 0, 0, i);
	}
	ans %= MOD;
	cout << ans << "\n";
	return 0;
}
