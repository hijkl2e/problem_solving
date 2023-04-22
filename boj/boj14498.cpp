#include <bits/stdc++.h>

using namespace std;

using ll = long long;
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
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<iii> A(K + 1);
	for (int i = 1; i <= K; ++i) {
		auto &[c, n, m] = A[i];
		cin >> n >> m >> c;
	}
	sort(A.begin(), A.end());
	MF mf(K + 2);
	int cnt{};
	for (int i = 1; i <= K; ++i) {
		if (get<0>(A[i])) {
			mf.add_edge(i, K + 1, 1);
		} else {
			mf.add_edge(0, i, 1);
			++cnt;
		}
	}
	for (int i = 1; i <= cnt; ++i) {
		for (int j = cnt + 1; j <= K; ++j) {
			if (get<1>(A[i]) == get<1>(A[j]) || get<2>(A[i]) == get<2>(A[j])) {
				mf.add_edge(i, j, 1);
			}
		}
	}
	cout << mf.dinic(0, K + 1) << "\n";
	return 0;
}
