#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using iii = tuple<ll, ll, ll>;

template <typename T = ll>
class LzSeg {
public:
	LzSeg(int sz) : n(sz), st(4 * sz), lz(4 * sz) { }
	void update(int i, int j, int q) {
		update(1, 0, n - 1, i, j, q);
	}
	int mex() {
		return mex(1, 0, n - 1);
	}
private:
	void propagate(int p, int l, int r) {
		if (lz[p] == 0) {
			return;
		}
		st[p] = lz[p] == 1 ? (r - l + 1) : lz[p] == 2 ? 0 : ((r - l + 1) - st[p]);
		if (l != r) {
			if (lz[p] == 3) {
				lz[2 * p] ^= 3;
				lz[2 * p + 1] ^= 3;
			} else {
				lz[2 * p] = lz[2 * p + 1] = lz[p];
			}
		}
		lz[p] = 0;
	}
	void update(int p, int l, int r, int i, int j, int q) {
		propagate(p, l, r);
		if (r < i || j < l) {
			return;
		} else if (i <= l && r <= j) {
			lz[p] = q;
			propagate(p, l, r);
			return;
		}
		int m = (l + r) / 2;
		update(2 * p, l, m, i, j, q);
		update(2 * p + 1, m + 1, r, i, j, q);
		st[p] = st[2 * p] + st[2 * p + 1];
	}
	int mex(int p, int l, int r) {
		propagate(p, l, r);
		if (st[p] == r - l + 1) {
			return -1;
		} else if (l == r) {
			return l;
		}
		int m = (l + r) / 2;
		int ret = mex(2 * p, l, m);
		if (ret == -1) {
			ret = mex(2 * p + 1, m + 1, r);
		}
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
	vector<iii> A(N);
	for (auto &[q, l, r] : A) {
		cin >> q >> l >> r;
	}
	vector<ll> B{0, 1};
	for (auto &[q, l, r] : A) {
		for (int i = -1; i < 2; ++i) {
			B.push_back(l + i);
			B.push_back(r + i);
		}
	}
	sort(B.begin(), B.end());
	B.resize(unique(B.begin(), B.end()) - B.begin());
	for (auto &[q, l, r] : A) {
		l = lower_bound(B.begin(), B.end(), l) - B.begin();
		r = lower_bound(B.begin(), B.end(), r) - B.begin();
	}
	LzSeg seg(B.size());
	seg.update(0, 0, 1);
	for (auto &[q, l, r] : A) {
		seg.update(l, r, q);
		cout << B[seg.mex()] << "\n";
	}
	return 0;
}
