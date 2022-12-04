#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, S{}, T{};
	cin >> N >> M >> S >> T;
	vector<vector<ll>> D(N + 1, vector<ll>(N + 1, INF));
	for (int i = 1; i <= N; ++i) {
		D[i][i] = 0;
	}
	while (M--) {
		ll u{}, v{}, w{};
		cin >> u >> v >> w;
		D[u][v] = min(D[u][v], w);
	}
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	int Q{};
	cin >> Q;
	while (Q--) {
		int a1{}, b1{}, c1{}, a2{}, b2{}, c2{};
		cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
		ll ans = D[S][T];
		ans = min(ans, D[S][a1] + c1 + D[b1][T]);
		ans = min(ans, D[S][a2] + c2 + D[b2][T]);
		ans = min(ans, D[S][a1] + c1 + D[b1][a2] + c2 + D[b2][T]);
		ans = min(ans, D[S][a2] + c2 + D[b2][a1] + c1 + D[b1][T]);
		cout << (ans == INF ? -1 : ans) << "\n";
	}
	return 0;
}
