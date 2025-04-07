#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

vector<vector<int>> G;
vector<ll> fact, sz;

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

ll solve(int x) {
	ll ret = 1;
	for (int y : G[x]) {
		ret = ret * solve(y) % MOD;
		sz[x] += sz[y];
	}
	int z = sz[x] - 1;
	for (int y : G[x]) {
		ret = ret * nCr(z, sz[y]) % MOD;
		z -= sz[y];
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	G.resize(N + 1);
	while (M--) {
		int a{}, b{};
		cin >> a >> b;
		G[a].push_back(b);
	}
	vector<int> ind(N + 1);
	for (int i = 1; i <= N; ++i) {
		for (int x : G[i]) {
			++ind[x];
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (ind[i] == 0) {
			G[0].push_back(i);
		}
	}
	fact.resize(N + 1);
	fact[0] = 1;
	for (int i = 1; i <= N; ++i) {
		fact[i] = fact[i - 1] * i % MOD;
	}
	sz.assign(N + 1, 1);
	cout << solve(0) << "\n";
	return 0;
}
