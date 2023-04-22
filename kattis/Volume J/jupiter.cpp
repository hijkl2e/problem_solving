#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
	int N{}, Q{}, S{};
	cin >> N >> Q >> S;
	vector<int> q(S);
	for (int i = 0; i < S; ++i) {
		cin >> q[i];
		--q[i];
	}
	vector<int> c(Q);
	for (int i = 0; i < Q; ++i) {
		cin >> c[i];
	}
	vector<int> d(N);
	vector<vector<int>> a(N, vector<int>(Q));
	for (int i = 0; i < N; ++i) {
		cin >> d[i];
		for (int j = 0; j < S; ++j) {
			int x{};
			cin >> x;
			a[i][q[j]] += x;
		}
	}
	MF mf((Q + 1) * N + 2);
	for (int i = 0; i < Q; ++i) {
		for (int j = 0; j < N; ++j) {
			int k = i * N + j;
			mf.add_edge((Q + 1) * N, k, min(a[j][i], c[i]));
			if (j) {
				mf.add_edge(k - 1, k, max(c[i] - a[j][i], 0));
			}
			mf.add_edge(k, k + (Q - i) * N, c[i]);
		}
	}
	for (int i = 0; i < N; ++i) {
		mf.add_edge(Q * N + i, (Q + 1) * N + 1, d[i]);
	}
	ll sum{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < Q; ++j) {
			sum += a[i][j];
		}
	}
	bool yes = mf.dinic((Q + 1) * N, (Q + 1) * N + 1) == sum;
	cout << (yes ? "possible" : "impossible") << "\n";
	return 0;
}
