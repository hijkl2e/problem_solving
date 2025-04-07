#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

template <typename T = ll>
class LzSeg {
public:
	LzSeg(int sz) : n(sz), st(4 * sz), lz1(4 * sz), lz2(4 * sz), B(sz) { }
	LzSeg(vector<T> &A) : LzSeg(A.size()) {
		build(A, 1, 0, n - 1);
	}
	void update(int t, int i, int j, T val) {
		update(1, 0, n - 1, t, i, j, val);
	}
	int lower_bound(T val) {
		return lower_bound(1, 0, n - 1, val);
	}
	vector<int> query() {
		update(1, 0, n - 1, 0, 0, n - 1, 0);
		return B;
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
		st[p] = max(st[2 * p], st[2 * p + 1]);
	}
	void propagate(int p, int l, int r) {
		if (lz1[p] == 0 && lz2[p] == 0) {
			return;
		}
		if (lz1[p]) {
			st[p] = lz1[p];
			if (l != r) {
				lz1[2 * p] = lz1[2 * p + 1] = lz1[p];
				lz2[2 * p] = lz2[2 * p + 1] = 0;
			}
		}
		st[p] += lz2[p];
		if (l != r) {
			lz2[2 * p] += lz2[p];
			lz2[2 * p + 1] += lz2[p];
		}
		lz1[p] = lz2[p] = 0;
	}
	void update(int p, int l, int r, int t, int i, int j, T val) {
		propagate(p, l, r);
		if (i > j || r < i || j < l) {
			return;
		} else if (i <= l && r <= j && t) {
			if (t == 1) {
				lz1[p] = val;
			} else {
				lz2[p] = val;
			}
			propagate(p, l, r);
			return;
		} else if (l == r) {
			B[l] = st[p];
			return;
		}
		int m = (l + r) / 2;
		update(2 * p, l, m, t, i, j, val);
		update(2 * p + 1, m + 1, r, t, i, j, val);
		st[p] = max(st[2 * p], st[2 * p + 1]);
	}
	int lower_bound(int p, int l, int r, T val) {
		propagate(p, l, r);
		if (st[p] < val) {
			return r + 1;
		} else if (l == r) {
			return l;
		}
		int m = (l + r) / 2;
		int ret = lower_bound(2 * p, l, m, val);
		if (ret == m + 1) {
			ret = lower_bound(2 * p + 1, m + 1, r, val);
		}
		return ret;
	}
	int n;
	vector<T> st, lz1, lz2, B;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{}, Q{};
	cin >> N >> M >> K >> Q;
	vector<ii> A(K);
	vector<ii> B(K);
	for (int i = 0; i < K; ++i) {
		cin >> A[i].first >> B[i].first;
		A[i].second = B[i].second = i;
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	vector<int> C(K);
	vector<int> D(K);
	for (int i = 0; i < K; ++i) {
		C[i] = A[i].first;
		D[i] = B[i].first;
	}
	LzSeg seg1(C);
	LzSeg seg2(D);
	while (Q--) {
		int x{}, y{}, t{};
		cin >> x >> y >> t;
		int p1 = seg1.lower_bound(x - t);
		int p2 = seg1.lower_bound(x + t + 1);
		seg1.update(1, p1, p2 - 1, x);
		seg1.update(2, 0, p1 - 1, t);
		seg1.update(2, p2, K - 1, -t);
		p1 = seg2.lower_bound(y - t);
		p2 = seg2.lower_bound(y + t + 1);
		seg2.update(1, p1, p2 - 1, y);
		seg2.update(2, 0, p1 - 1, t);
		seg2.update(2, p2, K - 1, -t);
	}
	C = seg1.query();
	D = seg2.query();
	vector<ii> E(K);
	for (int i = 0; i < K; ++i) {
		E[A[i].second].first = C[i];
		E[B[i].second].second = D[i];
	}
	for (int i = 0; i < K; ++i) {
		cout << E[i].first << " " << E[i].second << "\n";
	}
	return 0;
}
