#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using rec = tuple<ll, int, ll, int, int, int>;

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
	int query(int i, int j) {
		return get<5>(query(1, 0, n - 1, i, j));
	}
private:
	rec conquer(const rec &a, const rec &b) {
		auto &[L1, l1, R1, r1, c1, t1] = a;
		auto &[L2, l2, R2, r2, c2, t2] = b;
		if (c2 == 0) {
			return a;
		} else if (c1 == 0) {
			return b;
		}
		rec ret = {L1, l1 == c1 && L1 == L2 ? l1 + l2 : l1,
				R2, r2 == c2 && R2 == R1 ? r2 + r1 : r2, c1 + c2, 0};
		auto &[L3, l3, R3, r3, c3, t3] = ret;
		t3 = max({t1, t2, l3, r3, R1 == L2 ? r1 + l2 : 0});
		return ret;
	}
	void build(vector<T> &A, int p, int l, int r) {
		if (l == r) {
			st[p] = {A[l], 1, A[l], 1, 1, 1};
			return;
		}
		int m = (l + r) / 2;
		build(A, 2 * p, l, m);
		build(A, 2 * p + 1, m + 1, r);
		st[p] = conquer(st[2 * p], st[2 * p + 1]);
	}
	void propagate(int p, int l, int r) {
		if (lz[p] == 0) {
			return;
		}
		get<0>(st[p]) += lz[p];
		get<2>(st[p]) += lz[p];
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
		st[p] = conquer(st[2 * p], st[2 * p + 1]);
	}
	rec query(int p, int l, int r, int i, int j) {
		propagate(p, l, r);
		if (r < i || j < l) {
			return rec();
		} else if (i <= l && r <= j) {
			return st[p];
		}
		int m = (l + r) / 2;
		return conquer(query(2 * p, l, m, i, j), query(2 * p + 1, m + 1, r, i, j));
	}
	int n;
	vector<rec> st;
	vector<T> lz;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A(N + 2);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	for (int i = N; i > 0; --i) {
		A[i] -= A[i - 1];
	}
	LzSeg seg(A);
	int M{};
	cin >> M;
	while (M--) {
		ll q{}, a{}, b{}, x{}, y{};
		cin >> q >> a >> b;
		if (q == 1) {
			cin >> x >> y;
			seg.update(a, a, x);
			seg.update(a + 1, b, y);
			seg.update(b + 1, b + 1, -(x + (b - a) * y));
		} else {
			int ans = seg.query(a + 1, b) + 1;
			cout << ans << "\n";
		}
	}
	return 0;
}
