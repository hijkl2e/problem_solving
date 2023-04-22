#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

template <typename T = ll>
class LzSeg {
public:
	LzSeg(int sz) : n(sz), st(4 * sz), lz(4 * sz) { }
	void update(int i, int j, T val) {
		update(1, 0, n - 1, i, j, val);
	}
	T rmq(int i, int j) {
		return rmq(1, 0, n - 1, i, j);
	}
private:
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
			return 0;
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
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		int ux{}, vx{};
		cin >> ux >> A[i].second >> vx >> A[i].first;
	}
	sort(A.begin(), A.end());
	vector<int> B(2 * N);
	for (int i = 0; i < N; ++i) {
		B[2 * i] = A[i].first;
		B[2 * i + 1] = A[i].second;
	}
	sort(B.begin(), B.end());
	B.resize(unique(B.begin(), B.end()) - B.begin());
	for (auto &[u, v] : A) {
		u = lower_bound(B.begin(), B.end(), u) - B.begin();
		v = lower_bound(B.begin(), B.end(), v) - B.begin();
	}
	LzSeg seg1(B.size());
	LzSeg seg2(B.size());
	for (auto &[u, v] : A) {
		seg1.update(u, v, 1);
	}
	ll ans{};
	for (auto &[u, v] : A) {
		ans = max(ans, seg1.rmq(0, B.size() - 1) + seg2.rmq(0, B.size() - 1));
		seg1.update(u, v, -1);
		seg2.update(u, v, 1);
	}
	cout << ans << "\n";
	return 0;
}
