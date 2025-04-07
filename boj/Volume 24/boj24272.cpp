#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

template <typename T = ll>
class Seg {
public:
	Seg(int sz) : n(sz), st1(4 * sz), st2(4 * sz) { }
	void update(int i, int j, T val) {
		update(1, 0, n - 1, i, j, val);
	}
	T query() {
		return st2[1];
	}
private:
	void update(int p, int l, int r, int i, int j, T val) {
		if (r < i || j < l) {
			return;
		} else if (i <= l && r <= j) {
			st1[p] += val;
		} else {
			int m = (l + r) / 2;
			update(2 * p, l, m, i, j, val);
			update(2 * p + 1, m + 1, r, i, j, val);
		}
		if (st1[p]) {
			st2[p] = r - l + 1;
		} else {
			st2[p] = l == r ? 0 : (st2[2 * p] + st2[2 * p + 1]);
		}
	}
	int n;
	vector<T> st1, st2;
};

vector<vector<int>> G;
vector<int> in, out;
int cntr;

void dfs(int x, int p) {
	in[x] = out[x] = ++cntr;
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		dfs(y, x);
		out[x] = out[y];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N + 1);
	vector<iii> E;
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		string s;
		cin >> u >> s >> v;
		int d = s == "->" ? 1 : s == "<-" ? -1 : 0;
		G[u].push_back(v);
		G[v].push_back(u);
		E.push_back({u, v, d});
	}
	in.resize(N + 1);
	out.resize(N + 1);
	dfs(1, -1);
	map<ii, int> D;
	Seg seg(N + 1);
	for (auto &[u, v, d] : E) {
		if (in[u] > in[v]) {
			swap(u, v);
			d *= -1;
		}
		D[{u, v}] = d;
		if (d == 1) {
			seg.update(in[v], out[v], 1);
		} else if (d == -1) {
			seg.update(1, in[v] - 1, 1);
			seg.update(out[v] + 1, N, 1);
		}
	}
	int Q{};
	cin >> Q;
	while (Q--) {
		int u{}, v{};
		string s;
		cin >> u >> s >> v;
		int nd = s == "->" ? 1 : s == "<-" ? -1 : 0;
		if (in[u] > in[v]) {
			swap(u, v);
			nd *= -1;
		}
		int &d = D[{u, v}];
		if (d == nd) {
			cout << N - seg.query() << "\n";
			continue;
		}
		for (int x : {d, nd}) {
			bool f = x == d;
			if (x == 1) {
				seg.update(in[v], out[v], f ? -1 : 1);
			} else if (x == -1) {
				seg.update(1, in[v] - 1, f ? -1 : 1);
				seg.update(out[v] + 1, N, f ? -1 : 1);
			}
		}
		d = nd;
		cout << N - seg.query() << "\n";
	}
	return 0;
}
