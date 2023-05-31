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
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<vector<int>> G(M + 1);
	while (K--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
	}
	int ans = 1e9;
	vector<int> A;
	for (int k = 1; k <= M; ++k) {
		MF mf(N + M + 2);
		for (int i = 1; i <= M; ++i) {
			mf.add_edge(0, i, i == k ? INF : 1);
		}
		for (int i = 1; i <= M; ++i) {
			for (int x : G[i]) {
				mf.add_edge(i, M + x, INF);
			}
		}
		for (int i = 1; i <= N; ++i) {
			mf.add_edge(M + i, N + M + 1, 1);
		}
		int res = mf.dinic(0, N + M + 1);
		if (ans <= res) {
			continue;
		}
		ans = res;
		A.clear();
		for (int i = 1; i <= M; ++i) {
			if (mf.d[i] != -1) {
				A.push_back(i);
			}
		}
	}
	cout << A.size() << "\n";
	for (int i = 0; i < A.size(); ++i) {
		cout << A[i] << (i == A.size() - 1 ? "\n" : " ");
	}
	return 0;
}
