#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using edge = tuple<int, int, int>;

const ll INF = 4e18;

class MF {
public:
	using edge = tuple<int, ll, ll>;
	MF(int V) : G(V), d(V), last(V) { }
	void add_edge(int u, int v, ll c, bool d = true) {
		G[u].push_back(E.size());
		E.push_back({v, c, 0});
		G[v].push_back(E.size());
		E.push_back({u, d ? 0 : c, 0});
	}
	ll dinic(int s, int t) {
		ll mf{};
		while (bfs(s, t)) {
			fill(last.begin(), last.end(), 0);
			while (ll f = dfs(s, t)) {
				mf += f;
			}
		}
		return mf;
	}
	vector<int> d;
private:
	bool bfs(int s, int t) {
		fill(d.begin(), d.end(), -1);
		queue<int> q;
		d[s] = 0;
		q.push(s);
		while (q.size()) {
			int u = q.front(); q.pop();
			for (int idx : G[u]) {
				auto &[v, cap, flow] = E[idx];
				if (d[v] == -1 && flow < cap) {
					d[v] = d[u] + 1;
					q.push(v);
					if (v == t) {
						return true;
					}
				}
			}
		}
		return false;
	}
	ll dfs(int u, int t, ll f = INF) {
		if (u == t) {
			return f;
		}
		for (int &i = last[u]; i < G[u].size(); ++i) {
			auto &[v, cap, flow] = E[G[u][i]];
			if (d[v] == d[u] + 1 && flow < cap) {
				if (ll pushed = dfs(v, t, min(f, cap - flow))) {
					flow += pushed;
					auto &rflow = get<2>(E[G[u][i] ^ 1]);
					rflow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}
	vector<edge> E;
	vector<vector<int>> G;
	vector<int> last;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<edge> E(M);
	int w_sum{};
	for (auto &[u, v, w] : E) {
		cin >> u >> v >> w;
		w_sum += w;
	}
	int s{}, t{};
	cin >> s >> t;
	int ans{};
	for (int i = 0; i < M; ++i) {
		MF mf(N + 1);
		for (int j = 0; j < M; ++j) {
			if (i == j) {
				continue;
			}
			auto &[u, v, w] = E[j];
			mf.add_edge(u, v, w, false);
		}
		auto &[u, v, w] = E[i];
		int res = mf.dinic(s, t);
		if ((mf.d[u] == -1) ^ (mf.d[v] == -1)) {
			ans = max(ans, w_sum - res);
		}
	}
	cout << ans << "\n";
	return 0;
}
