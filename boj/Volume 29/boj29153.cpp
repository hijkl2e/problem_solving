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

vector<vector<int>> H;
vector<int> C;

void dfs(int x) {
	for (int y : H[x]) {
		if (C[y] == -1) {
			C[y] = C[x] ^ 1;
			dfs(y);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> G(N + 1);
	while (M--) {
		int a{}, b{};
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> A;
	for (int i = 1; i <= N; ++i) {
		if (G[i].size() > 2) {
			A.push_back(i);
		}
	}
	int n = A.size();
	H.resize(n);
	for (int i = 1; i <= N; ++i) {
		if (G[i].size() == 2) {
			int u = G[i][0], v = G[i][1];
			u = lower_bound(A.begin(), A.end(), u) - A.begin();
			v = lower_bound(A.begin(), A.end(), v) - A.begin();
			H[u].push_back(v);
			H[v].push_back(u);
		}
	}
	C.assign(n, -1);
	for (int i = 0; i < n; ++i) {
		if (C[i] == -1) {
			C[i] = 0;
			dfs(i);
		}
	}
	MF mf(n + 2);
	for (int u = 0; u < n; ++u) {
		if (C[u]) {
			mf.add_edge(u, n + 1, 1);
			continue;
		}
		mf.add_edge(n, u, 1);
		for (int v : H[u]) {
			mf.add_edge(u, v, 1);
		}
	}
	int ans = n - mf.dinic(n, n + 1);
	cout << ans << "\n";
	return 0;
}
