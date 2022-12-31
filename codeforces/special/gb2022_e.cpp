#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

vector<vector<int>> G;
vector<ll> A;
vector<int> sz, par;

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

void dfs(int x) {
	sz[x] = A[x];
	for (int y : G[x]) {
		if (y == par[x]) {
			continue;
		}
		par[y] = x;
		dfs(y);
		sz[x] += sz[y];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	A.resize(N + 1);
	for (int i = 0; i < K; ++i) {
		int x{};
		cin >> x;
		A[x] = 1;
	}
	G.resize(N + 1);
	vector<int> U(N - 1);
	vector<int> V(N - 1);
	for (int i = 0; i < N - 1; ++i) {
		auto &u = U[i], &v = V[i];
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	sz.resize(N + 1);
	par.assign(N + 1, -1);
	dfs(1);
	ll ans{};
	for (int i = 0; i < N - 1; ++i) {
		auto &u = U[i], &v = V[i];
		if (v == par[u]) {
			swap(u, v);
		}
		ans += (2 * A[u] * A[v] - (A[u] + A[v]) + 2) % MOD * sz[v] % MOD * (K - sz[v]) % MOD;
		ans += A[u] * (1 - A[v]) % MOD * (sz[v] + 1) % MOD * (K - sz[v] - 1) % MOD;
		ans += A[v] * (1 - A[u]) % MOD * (sz[v] - 1) % MOD * (K - sz[v] + 1) % MOD;
		A[u] = A[v] = 499122177 * (A[u] + A[v]) % MOD;
	}
	ans = (ans % MOD + MOD) % MOD * pow(1LL * K * (K - 1) % MOD, MOD - 2) % MOD;
	cout << ans << "\n";
	return 0;
}
