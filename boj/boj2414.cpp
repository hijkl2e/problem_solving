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
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<vector<int>> B(N, vector<int>(M));
	vector<vector<int>> C(N, vector<int>(M));
	vector<int> sz(2);
	for (int k = 0; k < 2; ++k) {
		auto &v = k ? C : B;
		for (int i = (k ? M : N) - 1; i >= 0; --i) {
			int x = k ? 0 : i, y = k ? i : 0;
			bool f = true;
			while (x < N && y < M) {
				if (A[x][y] == '.') {
					f = true;
					x += k, y += k ^ 1;
					continue;
				}
				if (f) {
					++sz[k], f = false;
				}
				v[x][y] = sz[k];
				x += k, y += k ^ 1;
			}
		}
	}
	MF mf(sz[0] + sz[1] + 2);
	for (int i = 0; i < sz[0]; ++i) {
		mf.add_edge(0, i + 1, 1);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (B[i][j]) {
				mf.add_edge(B[i][j], sz[0] + C[i][j], 1);
			}
		}
	}
	for (int i = 0; i < sz[1]; ++i) {
		mf.add_edge(sz[0] + i + 1, sz[0] + sz[1] + 1, 1);
	}
	cout << mf.dinic(0, sz[0] + sz[1] + 1) << "\n";
	return 0;
}
