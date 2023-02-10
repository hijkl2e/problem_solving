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
	LzSeg seg(C);
	deque<bool> D(N + 1);
	vector<vector<int>> E(401);
	for (int i = 1; i <= N; ++i) {
		seg.update(A[i], B[i], -1);
		for (int j = A[i]; j <= B[i] && j < 401; ++j) {
			E[j].push_back(i);
		}
		int res = seg.query();
		cout << res;
		if (res == 0) {
			cout << "\n";
			continue;
		}
		C.clear();
		if (res < 401) {
			for (int x : E[res]) {
				if (!D[x]) {
					C.push_back(x);
				}
			}
			E[res].clear();
		} else {
			for (int j = 1; j <= i; ++j) {
				if (!D[j] && A[j] <= res && res <= B[j]) {
					C.push_back(j);
				}
			}
		}
		for (int x : C) {
			D[x] = true;
			seg.update(A[x], B[x], 1);
			cout << " " << x;
		}
		cout << "\n";
	}
	return 0;
}
