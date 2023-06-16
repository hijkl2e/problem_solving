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
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		vector<int> x(N + M);
		vector<int> y(N + M);
		vector<string> A(N + M);
		for (int i = 0; i < A.size(); ++i) {
			cin >> x[i] >> y[i] >> A[i];
		}
		MF mf(N + M + 2);
		for (int i = 0; i < N; ++i) {
			mf.add_edge(N + M, i, 1);
		}
		for (int i = 0; i < N; ++i) {
			for (int j = N; j < N + M; ++j) {
				if (x[i] <= x[j] && x[j] < x[i] + A[i].size()
						&& y[j] <= y[i] && y[i] < y[j] + A[j].size()
						&& A[i][x[j] - x[i]] != A[j][y[i] - y[j]]) {
					mf.add_edge(i, j, 1);
				}
			}
		}
		for (int i = 0; i < M; ++i) {
			mf.add_edge(N + i, N + M + 1, 1);
		}
		int ans = N + M - mf.dinic(N + M, N + M + 1);
		cout << ans << "\n";
	}
	return 0;
}
