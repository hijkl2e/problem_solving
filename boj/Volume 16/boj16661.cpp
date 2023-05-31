#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9 + 7;

// from koosaga's library
struct WMCM {
	WMCM(int _n) : n(2 * _n + 1), g(n, vector<edge>(n)), lab(n), match(n), slack(n), st(n), pa(n),
			S(n), vis(n), flo_from(n, vector<int>(n / 2 + 1)), flo(n) {
		n /= 2;
		for (int u = 1; u <= n; ++u) {
			for (int v = 1; v <= n; ++v) {
				g[u][v] = edge(u, v, 0);
			}
		}
	}
	struct edge {
		edge() { }
		edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) { }
		int u{}, v{}, w{};
	};
	int e_delta(const edge &e) {
		return lab[e.u] + lab[e.v] - 2 * g[e.u][e.v].w;
	}
	void update_slack(int u, int x) {
		if (slack[x] == 0 || e_delta(g[u][x]) < e_delta(g[slack[x]][x])) {
			slack[x] = u;
		}
	}
	void set_slack(int x) {
		slack[x] = 0;
		for (int u = 1; u <= n; ++u) {
			if (g[u][x].w && st[u] != x && S[st[u]] == 0) {
				update_slack(u, x);
			}
		}
	}
	void q_push(int x) {
		if (x <= n) {
			q.push(x);
		} else {
			for (int i = 0; i < flo[x].size(); ++i) {
				q_push(flo[x][i]);
			}
		}
	}
	void set_st(int x, int b) {
		st[x] = b;
		if (x > n) {
			for (int i = 0; i < flo[x].size(); ++i) {
				set_st(flo[x][i], b);
			}
		}
	}
	int get_pr(int b, int xr) {
		int pr = find(flo[b].begin(), flo[b].end(), xr) - flo[b].begin();
		if (pr % 2) {
			reverse(flo[b].begin() + 1, flo[b].end());
			return flo[b].size() - pr;
		} else {
			return pr;
		}
	}
	void set_match(int u, int v) {
		match[u] = g[u][v].v;
		if (u <= n) {
			return;
		}
		edge e = g[u][v];
		int xr = flo_from[u][e.u], pr = get_pr(u, xr);
		for (int i = 0; i < pr; ++i) {
			set_match(flo[u][i], flo[u][i ^ 1]);
		}
		set_match(xr, v);
		rotate(flo[u].begin(), flo[u].begin() + pr, flo[u].end());
	}
	void augment(int u, int v) {
		while (true) {
			int xnv = st[match[u]];
			set_match(u, v);
			if (xnv == 0) {
				return;
			}
			set_match(xnv, st[pa[xnv]]);
			u = st[pa[xnv]], v = xnv;
		}
	}
	int get_lca(int u, int v) {
		static int t{};
		for (++t; u || v; swap(u, v)) {
			if (u == 0) {
				continue;
			} else if (vis[u] == t) {
				return u;
			}
			vis[u] = t;
			u = st[match[u]];
			if (u) {
				u = st[pa[u]];
			}
		}
		return 0;
	}
	void add_blossom(int u, int lca, int v) {
		int b = n + 1;
		while (b <= n_x && st[b]) {
			++b;
		}
		if (b > n_x) {
			++n_x;
		}
		lab[b] = 0, S[b] = 0;
		match[b] = match[lca];
		flo[b].clear();
		flo[b].push_back(lca);
		for (int x = u, y = 0; x != lca; x = st[pa[y]]) {
			flo[b].push_back(x);
			flo[b].push_back(y = st[match[x]]);
			q_push(y);
		}
		reverse(flo[b].begin() + 1, flo[b].end());
		for (int x = v, y = 0; x != lca; x = st[pa[y]]) {
			flo[b].push_back(x);
			flo[b].push_back(y = st[match[x]]);
			q_push(y);
		}
		set_st(b, b);
		for (int x = 1; x <= n_x; ++x) {
			g[b][x].w = g[x][b].w = 0;
		}
		for (int x = 1; x <= n; ++x) {
			flo_from[b][x] = 0;
		}
		for (int i = 0; i < flo[b].size(); ++i) {
			int xs = flo[b][i];
			for (int x = 1; x <= n_x; ++x) {
				if (g[b][x].w == 0 || e_delta(g[xs][x]) < e_delta(g[b][x])) {
					g[b][x] = g[xs][x], g[x][b] = g[x][xs];
				}
			}
			for (int x = 1; x <= n; ++x) {
				if (flo_from[xs][x]) {
					flo_from[b][x] = xs;
				}
			}
		}
		set_slack(b);
	}
	void expand_blossom(int b) {
		for (int i = 0; i < flo[b].size(); ++i) {
			set_st(flo[b][i], flo[b][i]);
		}
		int xr = flo_from[b][g[b][pa[b]].u], pr = get_pr(b, xr);
		for (int i = 0; i < pr; i += 2) {
			int xs = flo[b][i], xns = flo[b][i + 1];
			pa[xs] = g[xns][xs].u;
			S[xs] = 1, S[xns] = 0;
			slack[xs] = 0, set_slack(xns);
			q_push(xns);
		}
		S[xr] = 1, pa[xr] = pa[b];
		for (int i = pr + 1; i < flo[b].size(); ++i) {
			int xs = flo[b][i];
			S[xs] = -1, set_slack(xs);
		}
		st[b] = 0;
	}
	bool on_found_edge(const edge &e) {
		int u = st[e.u], v = st[e.v];
		if (S[v] == -1) {
			pa[v] = e.u, S[v] = 1;
			int nu = st[match[v]];
			slack[v] = slack[nu] = 0;
			S[nu] = 0, q_push(nu);
		} else if (S[v] == 0) {
			int lca = get_lca(u, v);
			if (lca == 0) {
				augment(u, v), augment(v, u);
				return true;
			} else {
				add_blossom(u, lca, v);
			}
		}
		return false;
	}
	bool matching() {
		fill(S.begin() + 1, S.begin() + n_x + 1, -1);
		fill(slack.begin() + 1, slack.begin() + n_x + 1, 0);
		q = queue<int>();
		for (int x = 1; x <= n_x; ++x) {
			if (st[x] == x && match[x] == 0) {
				pa[x] = S[x] = 0, q_push(x);
			}
		}
		if (q.empty()) {
			return false;
		}
		while (true) {
			while (q.size()) {
				int u = q.front(); q.pop();
				if (S[st[u]] == 1) {
					continue;
				}
				for (int v = 1; v <= n; ++v) {
					if (g[u][v].w && st[u] != st[v]) {
						if (e_delta(g[u][v]) == 0) {
							if (on_found_edge(g[u][v])) {
								return true;
							}
						} else {
							update_slack(u, st[v]);
						}
					}
				}
			}
			int d = INF;
			for (int b = n + 1; b <= n_x; ++b) {
				if (st[b] == b && S[b] == 1) {
					d = min(d, lab[b] / 2);
				}
			}
			for (int x = 1; x <= n_x; ++x) {
				if (st[x] == x && slack[x]) {
					if (S[x] == -1) {
						d = min(d, e_delta(g[slack[x]][x]));
					} else if (S[x] == 0) {
						d = min(d, e_delta(g[slack[x]][x]) / 2);
					}
				}
			}
			for (int u = 1; u <= n; ++u) {
				if (S[st[u]] == 0) {
					if (lab[u] <= d) {
						return 0;
					}
					lab[u] -= d;
				} else if (S[st[u]] == 1) {
					lab[u] += d;
				}
			}
			for (int b = n + 1; b <= n_x; ++b) {
				if (st[b] == b) {
					if (S[st[b]] == 0) {
						lab[b] += 2 * d;
					} else if (S[st[b]] == 1) {
						lab[b] -= 2 * d;
					}
				}
			}
			q = queue<int>();
			for (int x = 1; x <= n_x; ++x) {
				if (st[x] == x && slack[x] && st[slack[x]] != x && e_delta(g[slack[x]][x]) == 0) {
					if (on_found_edge(g[slack[x]][x])) {
						return true;
					}
				}
			}
			for (int b = n + 1; b <= n_x; ++b) {
				if (st[b] == b && S[b] == 1 && lab[b] == 0) {
					expand_blossom(b);
				}
			}
		}
		return false;
	}
	pair<ll, int> solve() {
		fill(match.begin() + 1, match.begin() + n + 1, 0);
		n_x = n;
		int n_matches{};
		ll tot_weight{};
		for (int u = 0; u <= n; ++u) {
			st[u] = u, flo[u].clear();
		}
		int w_max{};
		for (int u = 1; u <= n; ++u) {
			for (int v = 1; v <= n; ++v) {
				flo_from[u][v] = u == v ? u : 0;
				w_max = max(w_max, g[u][v].w);
			}
		}
		for (int u = 1; u <= n; ++u) {
			lab[u] = w_max;
		}
		while (matching()) {
			++n_matches;
		}
		for (int u = 1; u <= n; ++u) {
			if (match[u] && match[u] < u) {
				tot_weight += g[u][match[u]].w;
			}
		}
		return {tot_weight, n_matches};
	}
	void add_edge(int u, int v, int w) {
		g[u][v].w = g[v][u].w = w;
	}
	int n{}, n_x{};
	vector<vector<edge>> g;
	vector<int> lab, match, slack, st, pa, S, vis;
	vector<vector<int>> flo_from, flo;
	queue<int> q;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		cin.ignore();
		WMCM wmcm(2 * N + M);
		for (int i = 1; i <= N; ++i) {
			string S;
			getline(cin, S);
			for (int j = 1; j <= M; ++j) {
				if (S[j - 1] == '1') {
					wmcm.add_edge(i, 2 * N + j, 1);
					wmcm.add_edge(N + i, 2 * N + j, 1);
				}
			}
			wmcm.add_edge(i, N + i, 1);
		}
		int ans = wmcm.solve().first - N;
		cout << ans << "\n";
	}
	return 0;
}
