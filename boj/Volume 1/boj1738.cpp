#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<ii>> G(N + 1);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, -w});
	}
	vector<ll> D(N + 1, INF);
	vector<int> par(N + 1, -1);
	D[1] = 0;
	for (int i = 0; i < 2 * N; ++i) {
		for (int u = 1; u <= N; ++u) {
			if (D[u] == INF) {
				continue;
			}
			for (auto &[v, w] : G[u]) {
				if (D[v] > D[u] + w) {
					D[v] = i < N - 1 ? D[u] + w : -INF;
					par[v] = u;
				}
			}
		}
	}
	if (abs(D[N]) == INF) {
		cout << "-1\n";
		return 0;
	}
	stack<int> st;
	st.push(N);
	int x = N;
	while (x > 1) {
		x = par[x];
		st.push(x);
	}
	while (st.size()) {
		x = st.top(); st.pop();
		cout << x << (st.size() ? " " : "\n");
	}
	return 0;
}
