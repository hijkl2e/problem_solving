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
	vector<int> last;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	int A{}, B{}, K{};
	cin >> A >> B >> K;
	vector<iii> E(M);
	vector<int> F;
	for (int i = 0; i < M; ++i) {
		auto &[u, v, c] = E[i];
		cin >> u >> v >> c;
		if (u == K || v == K) {
			F.push_back(i);
		}
	}
	MF mf(N + 1);
	for (auto &[u, v, c] : E) {
		mf.add_edge(u, v, c, false);
	}
	int ans = mf.dinic(A, B);
	vector<ii> C;
	for (int x : F) {
		auto &[ux, vx, cx] = E[x];
		mf = MF(N + 1);
		for (int i = 0; i < M; ++i) {
			if (i == x) {
				continue;
			}
			auto &[u, v, c] = E[i];
			mf.add_edge(u, v, c, false);
		}
		if (mf.dinic(A, B) == ans - cx) {
			C.push_back({ux, vx});
			for (int u = 1; u <= N; ++u) {
				if (mf.d[u] == -1) {
					continue;
				}
				for (int idx : mf.G[u]) {
					auto &[v, cap, flow] = mf.E[idx];
					if (mf.d[v] == -1) {
						C.push_back({u, v});
					}
				}
			}
			break;
		}
	}
	cout << ans << "\n";
	if (C.size()) {
		cout << C.size() << "\n";
		for (auto &[u, v] : C) {
			cout << u << " " << v << "\n";
		}
	} else {
		cout << "-1\n";
	}
	return 0;
}
