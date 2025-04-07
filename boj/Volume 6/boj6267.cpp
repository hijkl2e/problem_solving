#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

class MCMF {
public:
	using edge = tuple<int, ll, ll, ll>;
	MCMF(int V) : G(V), d(V), last(V), vst(V) { }
	void add_edge(int u, int v, ll w, ll c, bool d = true) {
		G[u].push_back(E.size());
		E.push_back({v, w, 0, c});
		G[v].push_back(E.size());
		E.push_back({u, 0, 0, -c});
		if (!d) {
			add_edge(v, u, w, c);
		}
	}
	pair<ll, ll> mcmf(int s, int t) {
		ll mf{};
		while (spfa(s, t)) {
			fill(last.begin(), last.end(), 0);
			while (ll f = dfs(s, t)) {
				mf += f;
			}
		}
		return {mf, tcost};
	}
private:
	bool spfa(int s, int t) {
		fill(d.begin(), d.end(), INF);
		queue<int> q;
		d[s] = 0, vst[s] = true;
		q.push(s);
		while (q.size()) {
			int u = q.front(); q.pop();
			vst[u] = false;
			for (int idx : G[u]) {
				auto &[v, cap, flow, cost] = E[idx];
				if (d[v] > d[u] + cost && flow < cap) {
					d[v] = d[u] + cost;
					if (!vst[v]) {
						vst[v] = true;
						q.push(v);
					}
				}
			}
		}
		return d[t] < INF;
	}
	ll dfs(int u, int t, ll f = INF) {
		if (u == t) {
			return f;
		}
		vst[u] = true;
		for (int &i = last[u]; i < G[u].size(); ++i) {
			auto &[v, cap, flow, cost] = E[G[u][i]];
			if (!vst[v] && d[v] == d[u] + cost && flow < cap) {
				if (ll pushed = dfs(v, t, min(f, cap - flow))) {
					tcost += pushed * cost;
					flow += pushed;
					auto &rflow = get<2>(E[G[u][i] ^ 1]);
					rflow -= pushed;
					vst[u] = false;
					return pushed;
				}
			}
		}
		vst[u] = false;
		return 0;
	}
	vector<edge> E;
	vector<vector<int>> G;
	vector<ll> d;
	vector<int> last;
	deque<bool> vst;
	ll tcost{};
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		vector<int> A(N);
		vector<int> B(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		for (int i = 0; i < N; ++i) {
			cin >> B[i];
		}
		int cnt{};
		for (int i = 0; i < N; ++i) {
			cnt += __builtin_popcount(A[i]) - __builtin_popcount(B[i]);
		}
		if (cnt) {
			cout << "Impossible\n";
			continue;
		}
		MCMF mcmf(12 * N + 2);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < 12; ++j) {
				if (A[i] & (1 << j)) {
					mcmf.add_edge(12 * N, 12 * i + j, 1, 0);
				}
				if (i < N - 1) {
					mcmf.add_edge(12 * i + j, 12 * (i + 1) + j, INF, 1, false);
				}
				if (j < 11) {
					mcmf.add_edge(12 * i + j, 12 * i + j + 1, INF, 1, false);
				}
				if (B[i] & (1 << j)) {
					mcmf.add_edge(12 * i + j, 12 * N + 1, 1, 0);
				}
			}
		}
		cout << mcmf.mcmf(12 * N, 12 * N + 1).second << "\n";
	}
	return 0;
}
