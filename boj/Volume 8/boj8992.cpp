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
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		int K = N + M;
		vector<int> x1(K);
		vector<int> y1(K);
		vector<int> x2(K);
		vector<int> y2(K);
		vector<int> w(K);
		for (int i = 0; i < K; ++i) {
			cin >> x1[i] >> y1[i] >> x2[i] >> y2[i] >> w[i];
			if (x1[i] > x2[i]) {
				swap(x1[i], x2[i]);
			}
			if (y1[i] > y2[i]) {
				swap(y1[i], y2[i]);
			}
		}
		MCMF mcmf(K + 2);
		for (int i = 0; i < N; ++i) {
			mcmf.add_edge(K, i, 1, 0);
		}
		for (int i = 0; i < N; ++i) {
			for (int j = N; j < K; ++j) {
				if (x1[i] <= x1[j] && x2[j] <= x2[i] && y1[j] <= y1[i] && y2[i] <= y2[j]) {
					mcmf.add_edge(i, j, 1, -w[i] * w[j]);
				}
			}
		}
		for (int i = N; i < K; ++i) {
			mcmf.add_edge(i, K + 1, 1, 0);
		}
		auto res = mcmf.mcmf(K, K + 1);
		cout << res.first << " " << -res.second << "\n";
	}
	return 0;
}
