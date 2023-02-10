#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9 + 7;

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
	int query() {
		return query(1, 0, n - 1);
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
		st[p] = min(st[2 * p], st[2 * p + 1]);
	}
	void propagate(int p, int l, int r) {
		if (lz[p] == 0) {
			return;
		}
		st[p] += lz[p];
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
			lz[p] += val;
			propagate(p, l, r);
			return;
		}
		int m = (l + r) / 2;
		update(2 * p, l, m, i, j, val);
		update(2 * p + 1, m + 1, r, i, j, val);
		st[p] = min(st[2 * p], st[2 * p + 1]);
	}
	int query(int p, int l, int r) {
		propagate(p, l, r);
		if (st[p]) {
			return -1;
		} else if (l == r) {
			return l;
		}
		int m = (l + r) / 2;
		int ret = query(2 * p + 1, m + 1, r);
		ret = ret == -1 ? query(2 * p, l, m) : ret;
		return ret;
	}
	int n;
	vector<T> st, lz;
};

template <typename T = ll>
class Seg {
public:
	Seg(int sz) : n(sz), st(2 * sz) { }
	void update(int l, int r, T val) {
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) {
				st[l++].push_back(val);
			}
			if (r & 1) {
				st[--r].push_back(val);
			}
		}
	}
	vector<int> query(int p) {
		vector<int> ret;
		for (p += n; p > 0; p /= 2) {
			copy(st[p].begin(), st[p].end(), back_inserter(ret));
			st[p].clear();
		}
		return ret;
	}
private:
	int n;
	vector<vector<T>> st;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	vector<int> B(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i] >> B[i];
	}
	vector<int> C(N + 1);
	for (int i = 1; i <= N; ++i) {
		C[i] = i;
	}
	LzSeg seg1(C);
	Seg seg2(N + 1);
	deque<bool> D(N + 1);
	for (int i = 1; i <= N; ++i) {
		seg1.update(A[i], B[i], -1);
		seg2.update(A[i], B[i] + 1, i);
		int res = seg1.query();
		cout << res;
		if (res == 0) {
			cout << "\n";
			continue;
		}
		C = seg2.query(res);
		sort(C.begin(), C.end());
		for (int x : C) {
			if (D[x]) {
				continue;
			}
			D[x] = true;
			seg1.update(A[x], B[x], 1);
			cout << " " << x;
		}
		cout << "\n";
	}
	return 0;
}
