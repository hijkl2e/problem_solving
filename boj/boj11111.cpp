#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

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
	vector<vector<int>> A{
		{10, 8, 7, 5, -1, 1}, {8, 6, 4, 3, -1, 1}, {7, 4, 3, 2, -1, 1},
		{5, 3, 2, 2, -1, 1}, {-1, -1, -1, -1, -1, -1}, {1, 1, 1, 1, -1, 0}
	};
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> B(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, B[i]);
	}
	MCMF mcmf(N * M + 2);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if ((i + j) % 2) {
				mcmf.add_edge(i * M + j, N * M + 1, 1, 0);
				continue;
			}
			mcmf.add_edge(N * M, i * M + j, 1, 0);
			for (int k = 0; k < 4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < N && 0 <= ny && ny < M) {
					mcmf.add_edge(i * M + j, nx * M + ny, 1, -A[B[i][j] - 'A'][B[nx][ny] - 'A']);
				}
			}
		}
	}
	cout << -mcmf.mcmf(N * M, N * M + 1).second << "\n";
	return 0;
}
