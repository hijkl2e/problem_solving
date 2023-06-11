#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

template <typename T = ll>
class LzSeg {
public:
	LzSeg(int sz) : n(sz), st(4 * sz), lz(4 * sz, -INF) { }
	void update(int i, int j, T val) {
		update(1, 0, n - 1, i, j, val);
	}
	T rmq(int i, int j) {
		return rmq(1, 0, n - 1, i, j);
	}
private:
	void propagate(int p, int l, int r) {
		if (lz[p] == -INF) {
			return;
		}
		st[p] = lz[p];
		if (l != r) {
			lz[2 * p] = lz[2 * p + 1] = lz[p];
		}
		lz[p] = -INF;
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
		st[p] = max(st[2 * p], st[2 * p + 1]);
	}
	T rmq(int p, int l, int r, int i, int j) {
		propagate(p, l, r);
		if (r < i || j < l) {
			return -INF;
		} else if (i <= l && r <= j) {
			return st[p];
		}
		int m = (l + r) / 2;
		return max(rmq(2 * p, l, m, i, j), rmq(2 * p + 1, m + 1, r, i, j));
	}
	int n;
	vector<T> st, lz;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> B[i] >> A[i];
		B[i] += A[i] - 1;
	}
	vector<int> C(2 * N);
	for (int i = 0; i < N; ++i) {
		C[2 * i] = A[i];
		C[2 * i + 1] = B[i];
	}
	sort(C.begin(), C.end());
	C.resize(unique(C.begin(), C.end()) - C.begin());
	for (int i = 0; i < N; ++i) {
		A[i] = lower_bound(C.begin(), C.end(), A[i]) - C.begin();
		B[i] = lower_bound(C.begin(), C.end(), B[i]) - C.begin();
	}
	LzSeg seg(C.size());
	for (int i = 0; i < N; ++i) {
		int x = seg.rmq(A[i], B[i]);
		seg.update(A[i], B[i], x + 1);
	}
	int ans = seg.rmq(0, C.size() - 1);
	cout << ans << "\n";
	return 0;
}
