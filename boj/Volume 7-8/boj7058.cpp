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
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<int>> B(N, vector<int>(M, -1));
	vector<vector<int>> C(N, vector<int>(M, -1));
	vector<int> D, E;
	for (int i = 0; i < N; ++i) {
		D.push_back(i);
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == 0) {
				B[i][j] = D.size() - 1;
			} else if (A[i][j] == 2) {
				D.push_back(i);
			}
		}
	}
	for (int j = 0; j < M; ++j) {
		E.push_back(j);
		for (int i = 0; i < N; ++i) {
			if (A[i][j] == 0) {
				C[i][j] = E.size() - 1;
			} else if (A[i][j] == 2) {
				E.push_back(j);
			}
		}
	}
	int sz = D.size() + E.size();
	MF mf(sz + 2);
	for (int i = 0; i < D.size(); ++i) {
		mf.add_edge(sz, i, 1);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == 0) {
				mf.add_edge(B[i][j], D.size() + C[i][j], 1);
			}
		}
	}
	for (int i = 0; i < E.size(); ++i) {
		mf.add_edge(D.size() + i, sz + 1, 1);
	}
	cout << mf.dinic(sz, sz + 1) << "\n";
	for (int i = 0; i < D.size(); ++i) {
		if (mf.d[i] == 1) {
			continue;
		}
		for (int x : mf.G[i]) {
			auto &[v, cap, flow] = mf.E[x];
			if (flow == 1) {
				cout << D[i] + 1 << " " << E[v - D.size()] + 1 << "\n";
			}
		}
	}
	return 0;
}
