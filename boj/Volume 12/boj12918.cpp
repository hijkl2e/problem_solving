#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const ll INF = 4e18;
const double EPS = 1e-9;

class MCMF {
public:
	using edge = tuple<int, ll, ll, double>;
	MCMF(int V) : G(V), d(V), last(V), vst(V) { }
	void add_edge(int u, int v, ll w, double c, bool d = true) {
		G[u].push_back(E.size());
		E.push_back({v, w, 0, c});
		G[v].push_back(E.size());
		E.push_back({u, 0, 0, -c});
		if (!d) {
			add_edge(v, u, w, c);
		}
	}
	pair<ll, double> mcmf(int s, int t) {
		ll mf{};
		double mcost{};
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
				if (d[v] > d[u] + cost + EPS && flow < cap) {
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
	vector<double> d;
	vector<int> last;
	deque<bool> vst;
	double tcost{};
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A, B;
	int x_sum{};
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		if (x < 0) {
			A.push_back({x, y});
		} else if (x > 0) {
			B.push_back({x, y});
		}
		x_sum += abs(x);
	}
	N = A.size() + B.size();
	MCMF mcmf(N + 2);
	for (int i = 0; i < A.size(); ++i) {
		mcmf.add_edge(N, i, 1, 0);
	}
	for (int i = 0; i < A.size(); ++i) {
		auto &[x1, y1] = A[i];
		for (int j = 0; j < B.size(); ++j) {
			auto &[x2, y2] = B[j];
			double c = sqrt((x1 + x2) * (x1 + x2) + (y1 - y2) * (y1 - y2)) + x1 - x2;
			mcmf.add_edge(i, A.size() + j, 1, c);
		}
	}
	for (int i = 0; i < B.size(); ++i) {
		mcmf.add_edge(A.size() + i, N + 1, 1, 0);
	}
	double ans = x_sum + mcmf.mcmf(N, N + 1).second + EPS;
	cout << fixed << setprecision(3);
	cout << ans << "\n";
	return 0;
}
