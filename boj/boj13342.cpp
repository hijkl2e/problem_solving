#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e9 + 7;

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
		ll mf{}, mcost{};
		while (spfa(s, t)) {
			fill(last.begin(), last.end(), 0);
			while (ll f = dfs(s, t)) {
				mf += f;
				mcost = min(mcost, tcost);
			}
		}
		return {mf, mcost};
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
	int N{}, C{}, M{}, w{}, d{};
	cin >> N >> C >> M >> w >> d;
	vector<int> B(C);
	for (int i = 0; i < C; ++i) {
		cin >> B[i];
	}
	vector<int> A(M + 1);
	for (int i = 1; i <= M; ++i) {
		cin >> A[i];
	}
	vector<vector<int>> D(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> D[i][j];
			D[i][j] = i == j ? 0 : D[i][j] ? D[i][j] : INF;
		}
	}
	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	MCMF mcmf(C + M + 2);
	for (int i = 0; i < C; ++i) {
		mcmf.add_edge(C + M, i, 1, 0);
	}
	for (int i = 0; i < C; ++i) {
		for (int j = 0; j < M; ++j) {
			int x = w * D[A[j]][B[i]] + d * D[B[i]][A[j + 1]] - w * D[A[j]][A[j + 1]];
			mcmf.add_edge(i, C + j, 1, x);
		}
	}
	for (int i = 0; i < M; ++i) {
		mcmf.add_edge(C + i, C + M + 1, 1, 0);
	}
	ll ans = mcmf.mcmf(C + M, C + M + 1).second;
	for (int i = 0; i < M; ++i) {
		ans += w * D[A[i]][A[i + 1]];
	}
	cout << ans << "\n";
	return 0;
}
