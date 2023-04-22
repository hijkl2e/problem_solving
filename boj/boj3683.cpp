#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ss = pair<string, string>;

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
	vector<int> d, last;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int c{}, d{}, v{};
		cin >> c >> d >> v;
		vector<ss> A(v);
		for (int i = 0; i < v; ++i) {
			cin >> A[i].first >> A[i].second;
		}
		sort(A.begin(), A.end());
		MF mf(v + 2);
		for (int i = 0; i < v; ++i) {
			if (A[i].first[0] == 'C') {
				mf.add_edge(v, i, 1);
			} else {
				mf.add_edge(i, v + 1, 1);
			}
		}
		for (int i = 0; i < v; ++i) {
			for (int j = i + 1; j < v; ++j) {
				if (A[i].first == A[j].second || A[i].second == A[j].first) {
					mf.add_edge(i, j, 1);
				}
			}
		}
		int ans = v - mf.dinic(v, v + 1);
		cout << ans << "\n";
	}
	return 0;
}
