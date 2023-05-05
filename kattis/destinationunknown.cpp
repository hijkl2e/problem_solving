#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int N;
vector<vector<ii>> G;

vector<int> dijkstra(int s) {
	vector<int> D(N + 1, INF);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({D[s] = 0, s});
	while (pq.size()) {
		auto [d, u] = pq.top(); pq.pop();
		if (D[u] < d) {
			continue;
		}
		for (auto &[v, w] : G[u]) {
			if (D[v] > D[u] + w) {
				pq.push({D[v] = D[u] + w, v});
			}
		}
	}
	return D;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int M{}, K{};
		cin >> N >> M >> K;
		G.assign(N + 1, {});
		int s{}, g{}, h{};
		cin >> s >> g >> h;
		while (M--) {
			int u{}, v{}, w{};
			cin >> u >> v >> w;
			G[u].push_back({v, w});
			G[v].push_back({u, w});
		}
		vector<int> A(K);
		for (int i = 0; i < K; ++i) {
			cin >> A[i];
		}
		vector<vector<int>> D(3);
		D[0] = dijkstra(s);
		D[1] = dijkstra(g);
		D[2] = dijkstra(h);
		vector<int> B;
		for (int x : A) {
			if (D[0][g] + D[1][h] + D[2][x] == D[0][x]
					|| D[0][h] + D[2][g] + D[1][x] == D[0][x]) {
				B.push_back(x);
			}
		}
		sort(B.begin(), B.end());
		for (int i = 0; i < B.size(); ++i) {
			cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
		}
	}
	return 0;
}
