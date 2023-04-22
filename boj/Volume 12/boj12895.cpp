#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
class LzSeg {
public:
	LzSeg(int sz) : n(sz), st(4 * sz, 1), lz(4 * sz) { }
	void update(int i, int j, T val) {
		update(1, 0, n - 1, i, j, val);
	}
	T query(int i, int j) {
		return query(1, 0, n - 1, i, j);
	}
private:
	void propagate(int p, int l, int r) {
		if (lz[p] == 0) {
			return;
		}
		st[p] = lz[p];
		if (l != r) {
			lz[2 * p] = lz[2 * p + 1] = lz[p];
		}
		lz[p] = 0;
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
		st[p] = st[2 * p] | st[2 * p + 1];
	}
	T query(int p, int l, int r, int i, int j) {
		propagate(p, l, r);
		if (r < i || j < l) {
			return 0;
		} else if (i <= l && r <= j) {
			return st[p];
		}
		int m = (l + r) / 2;
		return query(2 * p, l, m, i, j) | query(2 * p + 1, m + 1, r, i, j);
	}
	int n;
	vector<T> st, lz;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, T{}, Q{};
	cin >> N >> T >> Q;
	LzSeg seg(N + 1);
	while (Q--) {
		char c{};
		int x{}, y{}, z{};
		cin >> c >> x >> y;
		if (x > y) {
			swap(x, y);
		}
		if (c == 'C') {
			cin >> z;
			seg.update(x, y, 1 << (z - 1));
		} else {
			cout << __builtin_popcount(seg.query(x, y)) << "\n";
		}
	}
	return 0;
}
