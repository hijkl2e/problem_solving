#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
class LzSeg {
public:
	LzSeg(int sz) : n(sz), st(4 * sz), lz(4 * sz, -1) { }
	void update(int i, int j, T val) {
		if (i <= j) {
			update(1, 0, n - 1, i, j, val);
		}
	}
	T rsq(int i, int j) {
		return i <= j ? rsq(1, 0, n - 1, i, j) : 0;
	}
private:
	void propagate(int p, int l, int r) {
		if (lz[p] == -1) {
			return;
		}
		st[p] = (r - l + 1) * lz[p];
		if (l != r) {
			lz[2 * p] = lz[2 * p + 1] = lz[p];
		}
		lz[p] = -1;
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
	LzSeg L(100005);
	LzSeg R(100005);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, K{};
		cin >> N >> K;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		int minv = *min_element(A.begin(), A.end());
		int maxv = *max_element(A.begin(), A.end());
		L.update(minv, maxv, 0);
		R.update(minv, maxv, 0);
		ll ans{};
		for (int i = 0; i < N; ++i) {
			int lo = max(A[i] - K, minv);
			int hi = min(A[i] + K, maxv);
			ans += i - L.rsq(hi + 1, maxv) - R.rsq(minv, lo - 1) + 1;
			L.update(A[i], A[i], L.rsq(A[i], hi) + 1);
			R.update(A[i], A[i], R.rsq(lo, A[i]) + 1);
			L.update(A[i] + 1, hi, 0);
			R.update(lo, A[i] - 1, 0);
		}
		cout << ans << "\n";
	}
	return 0;
}
