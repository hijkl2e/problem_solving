#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

template <typename T = ll>
class LzSeg {
public:
	LzSeg(int sz) : n(sz), st(4 * sz), lz1(4 * sz, 1), lz2(4 * sz) { }
	LzSeg(vector<T> &A) : LzSeg(A.size()) {
		build(A, 1, 0, n - 1);
	}
	void update(int i, int j, T v1, T v2) {
		update(1, 0, n - 1, i, j, v1, v2);
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
		st[p] = (st[2 * p] + st[2 * p + 1]) % MOD;
	}
	void propagate(int p, int l, int r) {
		T &v1 = lz1[p], &v2 = lz2[p];
		if (v1 == 1 && v2 == 0) {
			return;
		}
		st[p] = (st[p] * v1 + (r - l + 1) * v2) % MOD;
		if (l != r) {
			for (int i = 0; i < 2; ++i) {
				lz1[2 * p + i] = lz1[2 * p + i] * v1 % MOD;
				lz2[2 * p + i] = (lz2[2 * p + i] * v1 + v2) % MOD;
			}
		}
		v1 = 1, v2 = 0;
	}
	void update(int p, int l, int r, int i, int j, T v1, T v2) {
		propagate(p, l, r);
		if (r < i || j < l) {
			return;
		} else if (i <= l && r <= j) {
			lz1[p] = lz1[p] * v1 % MOD;
			lz2[p] = (lz2[p] * v1 + v2) % MOD;
			propagate(p, l, r);
			return;
		}
		int m = (l + r) / 2;
		update(2 * p, l, m, i, j, v1, v2);
		update(2 * p + 1, m + 1, r, i, j, v1, v2);
		st[p] = (st[2 * p] + st[2 * p + 1]) % MOD;
	}
	T rsq(int p, int l, int r, int i, int j) {
		propagate(p, l, r);
		if (r < i || j < l) {
			return 0;
		} else if (i <= l && r <= j) {
			return st[p];
		}
		int m = (l + r) / 2;
		return (rsq(2 * p, l, m, i, j) + rsq(2 * p + 1, m + 1, r, i, j)) % MOD;
	}
	int n;
	vector<T> st, lz1, lz2;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	LzSeg seg(A);
	int M{};
	cin >> M;
	while (M--) {
		int q{}, x{}, y{}, v{};
		cin >> q >> x >> y;
		--x, --y;
		if (q == 4) {
			cout << seg.rsq(x, y) << "\n";
			continue;
		}
		cin >> v;
		if (q == 1) {
			seg.update(x, y, 1, v);
		} else if (q == 2) {
			seg.update(x, y, v, 0);
		} else {
			seg.update(x, y, 0, v);
		}
	}
	return 0;
}
