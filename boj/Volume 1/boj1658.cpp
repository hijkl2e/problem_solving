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
	cin >> M >> N;
	MF mf(N + M + 2);
	for (int i = 1; i <= M; ++i) {
		int x{};
		cin >> x;
		mf.add_edge(N + i, N + M + 1, x);
	}
	vector<vector<int>> A(M + 1);
	for (int i = 1; i <= N; ++i) {
		int k{};
		cin >> k;
		while (k--) {
			int x{};
			cin >> x;
			mf.add_edge(i, N + x, INF);
			A[x].push_back(i);
		}
		cin >> k;
		mf.add_edge(0, i, k);
	}
	vector<deque<bool>> B(N + 1, deque<bool>(N + 1));
	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j < A[i].size(); ++j) {
			B[A[i][j]][A[i][j - 1]] = true;
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (B[i][j]) {
				mf.add_edge(i, j, INF);
			}
		}
	}
	cout << mf.dinic(0, N + M + 1) << "\n";
	return 0;
}
