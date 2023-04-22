#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
class LzSeg {
public:
	LzSeg(int sz) : n(sz), st(4 * sz), lz(4 * sz) { }
	void update(int i, int j) {
		update(1, 0, n - 1, i, j);
	}
	T query(int i, int j) {
		return query(1, 0, n - 1, i, j);
	}
private:
	void propagate(int p, int l, int r) {
		if (!lz[p]) {
			return;
		}
		st[p] = r - l + 1 - st[p];
		if (l != r) {
			lz[2 * p] ^= lz[p];
			lz[2 * p + 1] ^= lz[p];
		}
		lz[p] = false;
	}
	void update(int p, int l, int r, int i, int j) {
		propagate(p, l, r);
		if (r < i || j < l) {
			return;
		} else if (i <= l && r <= j) {
			lz[p] = true;
			propagate(p, l, r);
			return;
		}
		int m = (l + r) / 2;
		update(2 * p, l, m, i, j);
		update(2 * p + 1, m + 1, r, i, j);
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
	vector<T> st;
	deque<bool> lz;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	LzSeg seg(N + 1);
	while (M--) {
		int q{}, a{}, b{};
		cin >> q >> a >> b;
		if (q == 0) {
			seg.update(a, b);
		} else {
			cout << seg.query(a, b) << "\n";
		}
	}
	return 0;
}
