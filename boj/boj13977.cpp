#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

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

vector<ll> fact(4e6 + 1);
vector<ll> ifact(4e6 + 1);

ll nCr(ll x, ll y) {
	return fact[x] * ifact[x - y] % MOD * ifact[y] % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	fact[0] = 1;
	for (int i = 1; i < fact.size(); ++i) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	ifact.back() = pow(fact.back(), MOD - 2);
	for (int i = ifact.size() - 2; i >= 0; --i) {
		ifact[i] = (i + 1) * ifact[i + 1] % MOD;
	}
	int M{};
	cin >> M;
	while (M--) {
		int N{}, K{};
		cin >> N >> K;
		cout << nCr(N, K) << "\n";
	}
	return 0;
}
