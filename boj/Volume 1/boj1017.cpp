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

deque<bool> sieve() {
	deque<bool> p(2001, true);
	p[0] = p[1] = false;
	for (int i = 2; i < p.size(); ++i) {
		if (p[i]) {
			for (int j = 2 * i; j < p.size(); j += i) {
				p[j] = false;
			}
		}
	}
	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	deque<bool> P = sieve();
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B;
	for (int k = 1; k < N; ++k) {
		if (!P[A[0] + A[k]]) {
			continue;
		}
		vector<int> C, D;
		for (int i = 1; i < N; ++i) {
			if (i == k) {
				continue;
			}
			if (A[i] % 2) {
				C.push_back(A[i]);
			} else {
				D.push_back(A[i]);
			}
		}
		if (C.size() != D.size()) {
			continue;
		}
		int n = C.size();
		MF mf(N);
		for (int i = 1; i <= n; ++i) {
			mf.add_edge(0, i, 1);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (P[C[i] + D[j]]) {
					mf.add_edge(i + 1, n + j + 1, 1);
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			mf.add_edge(n + i, N - 1, 1);
		}
		if (mf.dinic(0, N - 1) == n) {
			B.push_back(A[k]);
		}
	}
	sort(B.begin(), B.end());
	if (B.size()) {
		for (int i = 0; i < B.size(); ++i) {
			cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
		}
	} else {
		cout << "-1\n";
	}
	return 0;
}
