#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<vector<ii>> G(N);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		--u, --v;
		G[u].push_back({v, w});
	}
	deque<bool> S(N);
	deque<bool> E(N);
	vector<int> A(N, -1);
	while (K--) {
		int k{};
		cin >> k;
		vector<int> P(k);
		for (int i = 0; i < k; ++i) {
			cin >> P[i];
			--P[i];
		}
		S[P[0]] = E[P[k - 1]] = true;
		for (int i = 0; i < k - 1; ++i) {
			A[P[i]] = P[i + 1];
		}
	}
	vector<ll> D(2 * N, INF);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	int s = S[0] ? N : 0;
	pq.push({D[s] = 0, s});
	while (pq.size()) {
		auto [d, u] = pq.top(); pq.pop();
		if (D[u] < d) {
			continue;
		}
		int u1 = u % N, u2 = u / N;
		if (E[u1] && u2) {
			continue;
		}
		for (auto &[v, w] : G[u1]) {
			int nv = v + (S[v] || (u2 && A[u1] == v) ? N : 0);
			if (D[nv] > D[u] + w) {
				pq.push({D[nv] = D[u] + w, nv});
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		ll d = min(D[i], E[i] ? INF : D[N + i]);
		cout << (d == INF ? -1 : d) << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
