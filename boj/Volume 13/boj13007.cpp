#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

vector<ll> fact, ifact;

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

ll nCr(ll n, ll r) {
	return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

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
	fact.resize(N + 1);
	fact[0] = 1;
	for (int i = 1; i <= N; ++i) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	ifact.resize(N + 1);
	ifact.back() = pow(fact.back(), MOD - 2);
	for (int i = ifact.size() - 2; i >= 0; --i) {
		ifact[i] = (i + 1) * ifact[i + 1] % MOD;
	}
	ll ans{};
	for (int i = max({A[1] - A[0], N - A[0] - A[2], 0}); i <= A[1] && i <= N - A[0]; ++i) {
		ans += nCr(N, A[0]) * nCr(N - A[0], i) % MOD * nCr(A[0], A[1] - i) % MOD
				* nCr(A[0] + i, A[2] - (N - A[0] - i)) % MOD;
	}
	ans %= MOD;
	cout << ans << "\n";
	return 0;
}
