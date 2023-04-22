#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

template <typename T = ll>
class LzSeg {
public:
	LzSeg(int sz) : n(sz), st(sz), lz1(4 * sz, -INF), lz2(4 * sz, INF) { }
	void update(int i, int j, T minv, T maxv) {
		update(1, 0, n - 1, i, j, minv, maxv);
	}
	vector<T> query() {
		query(1, 0, n - 1);
		return st;
	}
private:
	void propagate(int p, int l, int r) {
		if (lz1[p] == -INF && lz2[p] == INF) {
			return;
		}
		if (l == r) {
			st[l] = min(max(st[l], lz1[p]), lz2[p]);
		} else {
			propagate(p, 2 * p);
			propagate(p, 2 * p + 1);
		}
		lz1[p] = -INF;
		lz2[p] = INF;
	}
	void propagate(int p, int c) {
		lz1[c] = min(max(lz1[c], lz1[p]), lz2[p]);
		lz2[c] = max(min(lz2[c], lz2[p]), lz1[p]);
	}
	void update(int p, int l, int r, int i, int j, T minv, T maxv) {
		propagate(p, l, r);
		if (r < i || j < l) {
			return;
		} else if (i <= l && r <= j) {
			lz1[p] = minv;
			lz2[p] = maxv;
			propagate(p, l, r);
			return;
		}
		int m = (l + r) / 2;
		update(2 * p, l, m, i, j, minv, maxv);
		update(2 * p + 1, m + 1, r, i, j, minv, maxv);
	}
	void query(int p, int l, int r) {
		propagate(p, l, r);
		if (l == r) {
			return;
		}
		int m = (l + r) / 2;
		query(2 * p, l, m);
		query(2 * p + 1, m + 1, r);
	}
	int n;
	vector<T> st, lz1, lz2;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	LzSeg seg(N);
	while (K--) {
		int q{}, l{}, r{}, h{};
		cin >> q >> l >> r >> h;
		seg.update(l, r, q == 1 ? h : -INF, q == 2 ? h : INF);
	}
	for (int x : seg.query()) {
		cout << x << "\n";
	}
	return 0;
}
