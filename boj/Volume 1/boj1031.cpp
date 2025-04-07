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
	void remove_edge() {
		int u = get<0>(E.back());
		E.pop_back();
		int v = get<0>(E.back());
		E.pop_back();
		G[u].pop_back();
		G[v].pop_back();
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
	vector<vector<int>> G;
	vector<int> d, last;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	vector<int> B(M);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < M; ++i) {
		cin >> B[i];
	}
	MF mf(N + M + 2);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			mf.add_edge(i, N + j, 1);
		}
	}
	for (int i = 0; i < N; ++i) {
		mf.add_edge(N + M, i, A[i]);
	}
	for (int i = 0; i < M; ++i) {
		mf.add_edge(N + i, N + M + 1, B[i]);
	}
	if (mf.dinic(N + M, N + M + 1) < accumulate(B.begin(), B.end(), 0)) {
		cout << "-1\n";
		return 0;
	}
	vector<deque<bool>> C(N, deque<bool>(M, true));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			auto &[v, cap, flow] = mf.E[2 * (i * M + j)];
			if (flow == 0) {
				C[i][j] = false;
				cap = 0;
				continue;
			}
			auto &rcap = get<1>(mf.E[2 * (i * M + j) + 1]);
			--rcap;
			mf.add_edge(N + M, i, 1);
			mf.add_edge(N + j, N + M + 1, 1);
			if (mf.dinic(N + M, N + M + 1)) {
				C[i][j] = false;
			} else {
				mf.remove_edge();
				mf.remove_edge();
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << C[i][j];
		}
		cout << "\n";
	}
	return 0;
}
