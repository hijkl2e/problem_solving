#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
class LzSeg {
public:
	LzSeg(int sz) : n(sz), st(4 * sz), lz(4 * sz, -1) { }
	void update(int i, int j, T val) {
		update(1, 0, n - 1, i, j, val);
	}
	T query(int i, int j) {
		return query(1, 0, n - 1, i, j);
	}
private:
	void propagate(int p, int l, int r) {
		if (lz[p] == -1) {
			return;
		}
		st[p] = (r - l + 1) * lz[p];
		if (l != r) {
			lz[2 * p] = lz[2 * p + 1] = lz[p];
		}
		lz[p] = -1;
	}
	void update(int p, int l, int r, int i, int j, T val) {
		propagate(p, l, r);
		if (r < i || j < l) {
			return;
		} else if (i <= l && r <= j) {
			lz[p] = val;
			propagate(p, l, r);
			return;
		}
		int m = (l + r) / 2;
		update(2 * p, l, m, i, j, val);
		update(2 * p + 1, m + 1, r, i, j, val);
		st[p] = st[2 * p] + st[2 * p + 1];
	}
	T query(int p, int l, int r, int i, int j) {
		propagate(p, l, r);
		if (r < i || j < l) {
			return 0;
		} else if (i <= l && r <= j) {
			return st[p];
		}
		int m = (l + r) / 2;
		return query(2 * p, l, m, i, j) + query(2 * p + 1, m + 1, r, i, j);
	}
	int n;
	vector<T> st, lz;
};

vector<vector<int>> G;
vector<int> in, out;
int cntr;

void dfs(int x) {
	in[x] = out[x] = ++cntr;
	for (int y : G[x]) {
		dfs(y);
		out[x] = out[y];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		int p{};
		cin >> p;
		G[p].push_back(i);
	}
	in.resize(N + 1);
	out.resize(N + 1);
	dfs(1);
	LzSeg seg(N + 1);
	int M{};
	cin >> M;
	while (M--) {
		int q{}, a{};
		cin >> q >> a;
		if (q == 3) {
			cout << out[a] - in[a] - seg.query(in[a] + 1, out[a]) << "\n";
		} else {
			seg.update(in[a] + 1, out[a], q == 2);
		}
	}
	return 0;
}
