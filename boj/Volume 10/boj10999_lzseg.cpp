#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
class LzSeg {
public:
	LzSeg(int sz) : n(sz), st(4 * sz), lz(4 * sz) { }
	LzSeg(vector<T> &A) : LzSeg(A.size()) {
		build(A, 1, 0, n - 1);
	}
	void update(int i, int j, T val) {
		update(1, 0, n - 1, i, j, val);
	}
	T rsq(int i, int j) {
		return rsq(1, 0, n - 1, i, j);
	}
private:
	void build(vector<T> &A, int p, int l, int r) {
		if (l == r) {
			st[p] = A[l];
			return;
		}
		int m = (l + r) / 2;
		build(A, 2 * p, l, m);
		build(A, 2 * p + 1, m + 1, r);
		st[p] = st[2 * p] + st[2 * p + 1];
	}
	void propagate(int p, int l, int r) {
		if (lz[p] == 0) {
			return;
		}
		st[p] += (r - l + 1) * lz[p];
		if (l != r) {
			lz[2 * p] += lz[p];
			lz[2 * p + 1] += lz[p];
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
		st[p] = st[2 * p] + st[2 * p + 1];
	}
	T rsq(int p, int l, int r, int i, int j) {
		propagate(p, l, r);
		if (r < i || j < l) {
			return 0;
		} else if (i <= l && r <= j) {
			return st[p];
		}
		int m = (l + r) / 2;
		return rsq(2 * p, l, m, i, j) + rsq(2 * p + 1, m + 1, r, i, j);
	}
	int n;
	vector<T> st, lz;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	LzSeg seg(A);
	M += K;
	while (M--) {
		ll a{}, b{}, c{}, d{};
		cin >> a >> b >> c;
		--b, --c;
		if (a == 1) {
			cin >> d;
			seg.update(b, c, d);
		} else {
			cout << seg.rsq(b, c) << "\n";
		}
	}
	return 0;
}
