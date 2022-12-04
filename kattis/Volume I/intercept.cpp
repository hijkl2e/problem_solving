#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using li = pair<ll, int>;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<li>> G(N);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({w, v});
	}
	int s{}, t{};
	cin >> s >> t;
	vector<ll> D(N, INF);
	priority_queue<li, vector<li>, greater<li>> pq;
	pq.push({D[s] = 0, s});
	while (pq.size()) {
		auto [d, u] = pq.top(); pq.pop();
		if (D[u] < d) {
			continue;
		}
		for (auto &[w, v] : G[u]) {
			if (D[v] > d + w) {
				pq.push({D[v] = d + w, v});
			}
		}
	}
	vector<vector<int>> H(N);
	for (int u = 0; u < N; ++u) {
		for (auto &[w, v] : G[u]) {
			if (D[v] == D[u] + w) {
				H[v].push_back(u);
			}
		}
	}
	deque<bool> vst(N);
	queue<int> q;
	vst[t] = true;
	q.push(t);
	vector<int> ans;
	while (q.size()) {
		int u = q.front(); q.pop();
		if (q.empty()) {
			ans.push_back(u);
		}
		for (int v : H[u]) {
			if (!vst[v]) {
				vst[v] = true;
				q.push(v);
			}
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
	}
	return 0;
}
