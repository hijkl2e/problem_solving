#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

class MF {
public:
	MF(int V) : G(V), cap(V, vector<ll>(V)), flow(V, vector<ll>(V)), d(V), last(V) { }
	void add_edge(int u, int v, ll c, bool d = true) {
		G[u].push_back(v);
		G[v].push_back(u);
		cap[u][v] = c;
		cap[v][u] = d ? 0 : c;
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
			for (int v : G[u]) {
				if (d[v] == -1 && flow[u][v] < cap[u][v]) {
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
			int v = G[u][i];
			if (d[v] == d[u] + 1 && flow[u][v] < cap[u][v]) {
				if (ll pushed = dfs(v, t, min(f, cap[u][v] - flow[u][v]))) {
					flow[u][v] += pushed;
					flow[v][u] -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}
	vector<vector<int>> G;
	vector<vector<ll>> cap, flow;
	vector<int> last;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<vector<int>> B(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> B[i][j];
		}
	}
	MF mf(N + 2);
	for (int i = 0; i < N; ++i) {
		if (A[i] == 1) {
			mf.add_edge(N, i, INF, false);
		} else if (A[i] == 2) {
			mf.add_edge(i, N + 1, INF, false);
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			mf.add_edge(i, j, B[i][j], false);
		}
	}
	cout << mf.dinic(N, N + 1) << "\n";
	vector<vector<int>> C(2);
	for (int i = 0; i < N; ++i) {
		C[mf.d[i] == -1].push_back(i + 1);
	}
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < C[i].size(); ++j) {
			cout << C[i][j] << (j == C[i].size() - 1 ? "" : " ");
		}
		cout << "\n";
	}
	return 0;
}
