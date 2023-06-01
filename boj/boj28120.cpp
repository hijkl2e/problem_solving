#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using rec = tuple<int, int, vector<int>>;

const ll INF = 4e18;

class MF {
public:
	using edge = tuple<int, ll, ll>;
	MF() { }
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
	vector<int> d, last;
};

int N, K, X;
vector<rec> A;
deque<bool> B;
MF mf;

int solve() {
	mf = MF(N + K + 2);
	for (int i = 0; i < N; ++i) {
		mf.add_edge(N + K, i, 1);
	}
	for (int i = 0; i < N; ++i) {
		if (B[i]) {
			for (int x : get<2>(A[i])) {
				mf.add_edge(i, N + x, 1);
			}
		}
	}
	for (int i = 0; i < K; ++i) {
		mf.add_edge(N + i, N + K + 1, X);
	}
	return mf.dinic(N + K, N + K + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K >> X;
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		get<1>(A[i]) = i + 1;
		auto &v = get<2>(A[i]);
		int C{};
		cin >> C;
		while (C--) {
			int x{};
			cin >> x;
			v.push_back(x - 1);
		}
	}
	for (int i = 0; i < N; ++i) {
		cin >> get<0>(A[i]);
	}
	sort(A.rbegin(), A.rend());
	B.resize(N);
	for (int i = 0, k = 0; i < N; ++i) {
		B[i] = true;
		if (solve() == k + 1) {
			++k;
		} else {
			B[i] = false;
		}
	}
	solve();
	vector<vector<int>> D(K);
	for (int i = 0; i < N; ++i) {
		for (int x : mf.G[i]) {
			auto &[v, cap, flow] = mf.E[x];
			if (flow == 1) {
				D[v - N].push_back(get<1>(A[i]));
			}
		}
	}
	for (int i = 0; i < K; ++i) {
		cout << D[i].size();
		for (int x : D[i]) {
			cout << " " << x;
		}
		cout << "\n";
	}
	return 0;
}
