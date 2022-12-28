#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

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
	vector<edge> E;
	vector<vector<int>> G;
	vector<int> d, last;
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
			if (d[v] != d[u] + 1 || flow == cap) {
				continue;
			}
			if (ll pushed = dfs(v, t, min(f, cap - flow))) {
				flow += pushed;
				auto &rflow = get<2>(E[G[u][i] ^ 1]);
				rflow -= pushed;
				return pushed;
			}
		}
		return 0;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	int A{}, B{}, K{};
	cin >> A >> B >> K;
	vector<iii> E(M);
	for (auto &[u, v, c] : E) {
		cin >> u >> v >> c;
	}
	MF mf(N + 1);
	for (auto &[u, v, c] : E) {
		mf.add_edge(u, v, c, false);
	}
	int ans = mf.dinic(A, B);
	vector<ii> C;
	for (int i = 0; i < E.size(); ++i) {
		auto &[ui, vi, ci] = E[i];
		if (ui != K && vi != K) {
			continue;
		}
		mf = MF(N + 1);
		for (int j = 0; j < E.size(); ++j) {
			if (i == j) {
				continue;
			}
			auto &[u, v, c] = E[j];
			mf.add_edge(u, v, c, false);
		}
		if (mf.dinic(A, B) > ans - ci) {
			continue;
		}
		C.push_back({ui, vi});
		for (int u = 1; u <= N; ++u) {
			if (mf.d[u] == -1) {
				continue;
			}
			for (int x : mf.G[u]) {
				auto &[v, cap, flow] = mf.E[x];
				if (mf.d[v] == -1) {
					C.push_back({u, v});
				}
			}
		}
		break;
	}
	cout << ans << "\n";
	if (C.empty()) {
		cout << "-1\n";
	} else {
		cout << C.size() << "\n";
		for (auto &[u, v] : C) {
			cout << u << " " << v << "\n";
		}
	}
	return 0;
}
