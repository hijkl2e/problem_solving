#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using iii = tuple<int, int, int>;

const ll INF = 4e18;

template <typename T = ll>
class LzSeg {
public:
	LzSeg(int sz) : n(sz), st(4 * sz), lz(4 * sz, INF) { }
	LzSeg(vector<T> &A) : LzSeg(A.size()) {
		build(A, 1, 0, n - 1);
	}
	void update(int i, int j, T val) {
		update(1, 0, n - 1, i, j, val);
	}
	T rmq(int i, int j) {
		return rmq(1, 0, n - 1, i, j);
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
		if (lz[p] == INF) {
			return;
		}
		st[p] = lz[p];
		if (l != r) {
			lz[2 * p] = lz[2 * p + 1] = lz[p];
		}
		lz[p] = INF;
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
		st[p] = min(st[2 * p], st[2 * p + 1]);
	}
	T rmq(int p, int l, int r, int i, int j) {
		propagate(p, l, r);
		if (r < i || j < l) {
			return INF;
		} else if (i <= l && r <= j) {
			return st[p];
		}
		int m = (l + r) / 2;
		return min(rmq(2 * p, l, m, i, j), rmq(2 * p + 1, m + 1, r, i, j));
	}
	int n;
	vector<T> st, lz;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	if (K == 1) {
		cout << "0\n";
		return 0;
	}
	vector<iii> A(N);
	for (auto &[k, l, r] : A) {
		cin >> l >> r >> k;
	}
	sort(A.begin(), A.end());
	vector<int> B;
	for (auto &[k, l, r] : A) {
		B.push_back(l);
		B.push_back(r);
	}
	sort(B.begin(), B.end());
	B.resize(unique(B.begin(), B.end()) - B.begin());
	for (auto &[k, l, r] : A) {
		l = lower_bound(B.begin(), B.end(), l) - B.begin();
		r = lower_bound(B.begin(), B.end(), r) - B.begin();
	}
	vector<ll> C(B.size(), INF);
	for (auto &[k, l, r] : A) {
		if (k > 1) {
			break;
		}
		for (int i = l; i <= r; ++i) {
			C[i] = 0;
		}
	}
	LzSeg seg(C);
	ll ans = INF;
	for (auto &[k, l, r] : A) {
		if (k == 1) {
			continue;
		}
		ll x = seg.rmq(l, r);
		if (k == K) {
			ans = min(ans, x + 1);
		} else {
			seg.update(l, r, x + 1);
		}
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
