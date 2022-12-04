#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int V{}, E{}, Q{};
	cin >> V >> E >> Q;
	vector<deque<bool>> G(V + 2e3, deque<bool>(V + 2e3));
	while (E--) {
		int a{}, b{};
		cin >> a >> b;
		G[a][b] = true;
	}
	bool trns{}, cmpl{};
	while (Q--) {
		int q{}, x{}, y{};
		cin >> q;
		if (q == 1) {
			for (int i = 0; i < V; ++i) {
				G[V][i] = G[i][V] = cmpl;
			}
			++V;
		} else if (q == 2 || q == 4) {
			cin >> x >> y;
			if (trns) {
				swap(x, y);
			}
			G[x][y] ^= true;
		} else if (q == 3) {
			cin >> x;
			for (int i = 0; i < V; ++i) {
				if (i == x) {
					continue;
				}
				G[x][i] = G[i][x] = cmpl;
			}
		} else if (q == 5) {
			trns ^= true;
		} else {
			cmpl ^= true;
		}
	}
	if (trns) {
		for (int i = 0; i < V; ++i) {
			for (int j = i + 1; j < V; ++j) {
				swap(G[i][j], G[j][i]);
			}
		}
	}
	if (cmpl) {
		for (int i = 0; i < V; ++i) {
			for (int j = 0; j < V; ++j) {
				if (i == j) {
					continue;
				}
				G[i][j] ^= true;
			}
		}
	}
	cout << V << "\n";
	for (int i = 0; i < V; ++i) {
		int cnt{};
		ll h{};
		for (int j = V - 1; j >= 0; --j) {
			if (G[i][j]) {
				h = (7 * h + j) % MOD;
				++cnt;
			}
		}
		cout << cnt << " " << h << "\n";
	}
	return 0;
}
