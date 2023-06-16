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
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cin.ignore();
		vector<string> A(N);
		for (int i = 0; i < N; ++i) {
			getline(cin, A[i]);
		}
		vector<int> B(N);
		vector<int> C(N);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				B[i] += A[i][j] == '1' ? 2 : A[i][j] == 'd' ? 1 : 0;
				C[i] += A[i][j] == '.';
			}
		}
		int sum = accumulate(C.begin(), C.end(), 0);
		vector<int> D;
		for (int i = 0; i < N; ++i) {
			if (*max_element(B.begin(), B.end()) > B[i] + 2 * C[i]) {
				continue;
			}
			B[i] += 2 * C[i];
			MF mf(N + 2);
			for (int j = 0; j < N; ++j) {
				mf.add_edge(N, j, j == i ? 0 : (C[j] - (A[j][i] == '.')));
			}
			for (int j = 0; j < N; ++j) {
				if (j == i) {
					continue;
				}
				for (int k = j + 1; k < N; ++k) {
					if (k == i) {
						continue;
					} else if (A[j][k] == '.') {
						mf.add_edge(j, k, 1, false);
					}
				}
			}
			for (int j = 0; j < N; ++j) {
				mf.add_edge(j, N + 1, B[i] - B[j]);
			}
			if (mf.dinic(N, N + 1) == sum - 2 * C[i]) {
				D.push_back(i + 1);
			}
			B[i] -= 2 * C[i];
		}
		for (int i = 0; i < D.size(); ++i) {
			cout << D[i] << (i == D.size() - 1 ? "\n" : " ");
		}
	}
	return 0;
}
