#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

const ll MOD = 1e9 + 7;

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

ll nCr(ll N, ll R) {
	return fact[N] * pow(fact[N - R] * fact[R] % MOD, MOD - 2) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> B(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> B[i];
	}
	vector<ll> C(N + 1);
	ll ans = 1;
	for (int i = 1; i <= N; ++i) {
		int j = i;
		int cnt{};
		while (B[j] != -1) {
			int k = B[j];
			B[j] = -1;
			j = k;
			++cnt;
		}
		ans &= j == i;
		++C[cnt];
	}
	fact.resize(N + 1);
	fact[0] = 1;
	for (int i = 1; i <= N; ++i) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	for (int i = 1; i <= N; ++i) {
		vector<ll> dp(C[i] + 1);
		dp[0] = 1;
		vector<ii> A;
		for (int j = 1; j <= C[i]; ++j) {
			if (K % j == 0 && gcd(K / j, i) == 1) {
				A.push_back({j, fact[j - 1] * pow(1LL * i, j - 1LL) % MOD});
			}
			for (auto &[u, v] : A) {
				dp[j] += dp[j - u] * v % MOD * nCr(j - 1, u - 1) % MOD;
			}
			dp[j] %= MOD;
		}
		ans = ans * dp[C[i]] % MOD;
	}
	cout << ans << "\n";
	return 0;
}
