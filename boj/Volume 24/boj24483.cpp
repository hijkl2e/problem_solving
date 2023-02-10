#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int N, cnt;
vector<vector<int>> G;
vector<int> D, T;

void dfs(int x, int p) {
	T[x] = ++cnt;
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		if (D[y] == -1) {
			D[y] = D[x] + 1;
			dfs(y, x);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{}, R{};
	cin >> N >> M >> R;
	G.resize(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= N; ++i) {
		sort(G[i].begin(), G[i].end());
	}
	D.assign(N + 1, -1);
	T.resize(N + 1);
	D[R] = 0;
	dfs(R, -1);
	ll ans{};
	for (int i = 1; i <= N; ++i) {
		ans += 1LL * D[i] * T[i];
	}
	cout << ans << "\n";
	return 0;
}
