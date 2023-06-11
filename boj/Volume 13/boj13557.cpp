#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using rec = tuple<ll, ll, ll, ll>;

const ll INF = 4e18;

class Seg {
public:
	Seg(int sz) : n(sz), st(2 * sz) { }
	Seg(vector<ll> &A) : n(A.size()), st(2 * A.size()) {
		for (int i = 0; i < n; ++i) {
			st[n + i] = {A[i], A[i], A[i], A[i]};
		}
		for (int i = n - 1; i > 0; --i) {
			st[i] = conquer(st[2 * i], st[2 * i + 1]);
		}
	}
	void update(int p, ll val) {
		st[p += n] = {val, val, val, val};
		for (p /= 2; p > 0; p /= 2) {
			st[p] = conquer(st[2 * p], st[2 * p + 1]);
		}
	}
	rec query(int l, int r) {
		rec L, R;
		L = R = {-INF, -INF, -INF, 0};
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) {
				L = conquer(L, st[l++]);
			}
			if (r & 1) {
				R = conquer(st[--r], R);
			}
		}
		return conquer(L, R);
	}
private:
	rec conquer(rec &L, rec &R) {
		auto &[l1, r1, t1, s1] = L;
		auto &[l2, r2, t2, s2] = R;
		return {max(l1, s1 + l2), max(r2, s2 + r1), max({t1, t2, r1 + l2}), s1 + s2};
	}
	int n;
	vector<rec> st;
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
	Seg seg(A);
	int M{};
	cin >> M;
	while (M--) {
		int x1{}, y1{}, x2{}, y2{};
		cin >> x1 >> y1 >> x2 >> y2;
		-- x1, --y1, --x2, --y2;
		ll ans{};
		if (y1 < x2) {
			auto [l1, r1, t1, s1] = seg.query(x1, y1 + 1);
			auto [l2, r2, t2, s2] = seg.query(y1 + 1, x2);
			auto [l3, r3, t3, s3] = seg.query(x2, y2 + 1);
			ans = r1 + s2 + l3;
		} else {
			auto [l1, r1, t1, s1] = seg.query(x1, x2);
			auto [l2, r2, t2, s2] = seg.query(x2, y1 + 1);
			auto [l3, r3, t3, s3] = seg.query(y1 + 1, y2 + 1);
			ans = max({t2, r1 + l2, r2 + l3, r1 + s2 + l3});
		}
		cout << ans << "\n";
	}
	return 0;
}
