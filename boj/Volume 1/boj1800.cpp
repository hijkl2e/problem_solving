#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e6 + 7;

int N, M, K;

vector<vector<ii>> G;

bool solve(int L) {
	vector<int> D(N + 1, INF);
	deque<int> dq;
	D[1] = 0;
	dq.push_back(1);
	while (dq.size()) {
		int u = dq.front(); dq.pop_front();
		for (auto &[v, w] : G[u]) {
			int nd = D[u] + (w > L);
			if (D[v] > nd) {
				D[v] = nd;
				if (w > L) {
					dq.push_back(v);
				} else {
					dq.push_front(v);
				}
			}
		}
	}
	return D[N] <= K;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> K;
	G.resize(N + 1);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	int lo = -1, hi = INF;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (solve(mid)) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << (hi == INF ? -1 : hi) << "\n";
	return 0;
}
