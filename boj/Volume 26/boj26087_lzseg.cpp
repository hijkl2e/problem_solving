#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

template <typename T = ll>
class LzSeg {
public:
	LzSeg(int sz) : n(sz), st(sz), lz(4 * sz) { }
	void update(int i, int j) {
		update(1, 0, n - 1, i, j);
	}
	vector<T> &query() {
		query(1, 0, n - 1);
		return st;
	}
private:
	void propagate(int p, int l, int r) {
		if (lz[p] == 0) {
			return;
		}
		if (l == r) {
			st[l] = lz[p];
		} else {
			lz[2 * p] = lz[p];
			lz[2 * p + 1] = lz[p] + (l + r) / 2 - l + 1;
		}
		lz[p] = 0;
	}
	void update(int p, int l, int r, int i, int j) {
		propagate(p, l, r);
		if (r < i || j < l) {
			return;
		} else if (i <= l && r <= j) {
			lz[p] = l - i + 1;
			propagate(p, l, r);
			return;
		}
		int m = (l + r) / 2;
		update(2 * p, l, m, i, j);
		update(2 * p + 1, m + 1, r, i, j);
	}
	void query(int p, int l, int r) {
		propagate(p, l, r);
		if (l == r) {
			return;
		}
		int m = (l + r) / 2;
		query(2 * p, l, m);
		query(2 * p + 1, m + 1, r);
	}
	int n;
	vector<T> st, lz;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	vector<ll> F(N + 1);
	F[0] = F[1] = 1;
	for (int i = 2; i <= N; ++i) {
		F[i] = (F[i - 1] + F[i - 2]) % MOD;
	}
	F[0] = 0;
	LzSeg<int> seg(N + 1);
	while (Q--) {
		int l{}, r{};
		cin >> l >> r;
		seg.update(l, r);
	}
	auto &ans = seg.query();
	for (int i = 1; i <= N; ++i) {
		cout << F[ans[i]] << (i == N ? "\n" : " ");
	}
	return 0;
}
