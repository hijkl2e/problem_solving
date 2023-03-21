#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937_64 gen(random_device{}());
vector<vector<int>> G;
vector<ll> A, E;
vector<int> B, C;
ll X;

void dfs(int x, int p) {
	B[x] = 0;
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		if (B[y] == -1) {
			C[y] = C[x] ^ 1;
			dfs(y, x);
			A[x] ^= A[y];
		} else if (B[y] == 0) {
			ll t = gen();
			E.push_back(t);
			A[x] ^= t;
			A[y] ^= t;
			if (C[x] == C[y]) {
				X ^= t;
			}
		}
	}
	E.push_back(A[x]);
	B[x] = 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	G.resize(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	A.resize(N + 1);
	B.assign(N + 1, -1);
	C.resize(N + 1);
	C[1] = 0;
	dfs(1, -1);
	sort(E.begin(), E.end());
	ll ans = X ? count(E.begin(), E.end(), X) : 1;
	if (ans == 0) {
		for (int i = 0, j = 1; i < E.size(); i = j++) {
			while (j < E.size() && E[i] == E[j]) {
				++j;
			}
			ll x = X ^ E[i];
			ans += (j - i) * (upper_bound(E.begin(), E.end(), x) - lower_bound(E.begin(), E.end(), x));
		}
		ans /= 2;
	}
	cout << ans << "\n";
	return 0;
}
