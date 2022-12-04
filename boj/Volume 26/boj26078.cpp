#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

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

ll nCr(ll x, ll y) {
	return fact[x] * pow(fact[x - y] * fact[y] % MOD, MOD - 2) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{};
	cin >> K;
	vector<ll> A(1 << K);
	for (int i = 0; i < A.size(); ++i) {
		cin >> A[i];
	}
	vector<ll> R(K);
	for (int i = 0; i < K; ++i) {
		cin >> R[i];
	}
	fact.resize((1 << K) + 1);
	fact[0] = 1;
	for (int i = 1; i < fact.size(); ++i) {
		fact[i] = fact[i - 1] * i % MOD;
	}
	int x = A[0];
	sort(A.begin(), A.end());
	x = find(A.begin(), A.end(), x) - A.begin();
	ll ans{};
	for (int i = 1; i <= K; ++i) {
		if (x < (1 << i) - 1) {
			break;
		}
		ans += nCr(x, (1 << i) - 1) * pow(nCr((1 << K) - 1, (1 << i) - 1), MOD - 2) % MOD * R[i - 1] % MOD;
	}
	ans %= MOD;
	cout << ans << "\n";
	return 0;
}
