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
	vector<vector<ll>> flow;
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
	vector<vector<ll>> cap;
	vector<int> d, last;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{}, N{};
	cin >> M >> N;
	vector<string> A(M + 1);
	vector<vector<int>> G(M + 1);
	for (int i = 1; i <= M; ++i) {
		cin >> A[i];
		int d{};
		cin >> d;
		G[i].resize(d);
		for (int j = 0; j < d; ++j) {
			cin >> G[i][j];
		}
	}
	vector<vector<int>> B(N + 1);
	for (int k = 1;; ++k) {
		MF mf(M + N + 2);
		for (int i = 1; i <= M; ++i) {
			mf.add_edge(0, i, k);
			for (int x : G[i]) {
				mf.add_edge(i, M + x, 1);
			}
		}
		for (int i = 1; i <= N; ++i) {
			mf.add_edge(M + i, M + N + 1, 2);
		}
		if (mf.dinic(0, M + N + 1) == 2 * N) {
			B[0].push_back(k);
			for (int i = 1; i <= M; ++i) {
				for (int j = 1; j <= N; ++j) {
					if (mf.flow[i][M + j]) {
						B[j].push_back(i);
					}
				}
			}
			break;
		}
	}
	cout << B[0][0] << "\n";
	for (int i = 1; i <= N; ++i) {
		cout << "Day " << i << ": ";
		cout << A[B[i][0]] << " " << A[B[i][1]] << "\n";
	}
	return 0;
}
