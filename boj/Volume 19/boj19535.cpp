#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<vector<int>> G;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ll d{}, g{};
	vector<ll> A(N + 1);
	for (int u = 1; u <= N; ++u) {
		for (int v : G[u]) {
			A[u] += G[v].size() - 1;
		}
	}
	for (int i = 1; i <= N; ++i) {
		d += A[i] * (G[i].size() - 1);
		g += G[i].size() * (G[i].size() - 1) * (G[i].size() - 2) / 6;
	}
	d /= 2;
	string ans;
	if (d > 3 * g) {
		ans = "D";
	} else if (d < 3 * g) {
		ans = "G";
	} else {
		ans = "DUDUDUNGA";
	}
	cout << ans << "\n";
	return 0;
}
