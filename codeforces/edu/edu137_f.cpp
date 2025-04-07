#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

template <typename T = ll>
class LzSeg {
public:
	LzSeg(int sz) : n(sz), st(sz), lz(4 * sz) { }
	void update(int i, int j, T val) {
		update(1, 0, n - 1, i, j, val);
	}
	T query(int i) {
		return query(1, 0, n - 1, i);
	}
private:
	void propagate(int p, int l, int r) {
		if (lz[p] == 0) {
			return;
		}
		if (l == r) {
			st[l] = lz[p];
		} else {
			lz[2 * p] = lz[2 * p + 1] = lz[p];
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
	}
	T query(int p, int l, int r, int i) {
		propagate(p, l, r);
		if (l == i && r == i) {
			return st[l];
		}
		int m = (l + r) / 2;
		if (i <= m) {
			return query(2 * p, l, m, i);
		} else {
			return query(2 * p + 1, m + 1, r, i);
		}
	}
	int n;
	vector<T> st, lz;
};

ll pow(ll x, ll y) {
	ll ret = 1;
	while (y) {
		if (y & 1) {
			ret = ret * x % MOD;
		}
		x = x * x % MOD;
		y /= 2;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int sz = 3e5 + 1;
	LzSeg<int> seg(sz);
	for (int i = 0; i < N; ++i) {
		int l{}, r{};
		cin >> l >> r;
		seg.update(l, r, i + 1);
	}
	ll ans{};
	for (int i = 0; i < sz; ++i) {
		int res = seg.query(i);
		if (res == 0) {
			continue;
		}
		ans += pow(3LL, max<ll>(res - 2, 0)) * pow(2LL, min<ll>(N - res + 1, N - 1)) % MOD;
	}
	ans %= MOD;
	cout << ans << "\n";
	return 0;
}
