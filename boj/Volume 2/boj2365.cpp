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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	int sum = accumulate(A.begin(), A.end(), 0);
	vector<vector<int>> C(N, vector<int>(N));
	int lo = 0, hi = 1e4;
	while (true) {
		int mid = lo + 1 < hi ? (lo + hi) / 2 : hi;
		MF mf((N + 2) * N + 2);
		for (int i = 0; i < N; ++i) {
			mf.add_edge((N + 2) * N, N * N + i, A[i]);
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				mf.add_edge(N * N + i, i * N + j, mid);
				mf.add_edge(i * N + j, (N + 1) * N + j, mid);
			}
		}
		for (int i = 0; i < N; ++i) {
			mf.add_edge((N + 1) * N + i, (N + 2) * N + 1, B[i]);
		}
		int res = mf.dinic((N + 2) * N, (N + 2) * N + 1);
		if (lo + 1 < hi) {
			if (res == sum) {
				hi = mid;
			} else {
				lo = mid;
			}
			continue;
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				int u = i * N + j;
				auto &[v, cap, flow] = mf.E[mf.G[u][1]];
				C[i][j] = flow;
			}
		}
		break;
	}
	cout << hi << "\n";
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << C[i][j] << (j == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
