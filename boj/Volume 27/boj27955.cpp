#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

const ll mod1 = 1e9 + 7;
const ll mod2 = 1e9 + 9;

ll pow(ll x, ll y, ll mod) {
	ll ret = 1;
	while (y) {
		if (y % 2) {
			ret = ret * x % mod;
		}
		x = x * x % mod;
		y /= 2;
	}
	return ret;
}

template <typename T = ll>
class LzSeg {
public:
	LzSeg(int sz, T m) : n(sz), st(4 * sz), lz(4 * sz), P(sz), Q(sz), R(sz), mod(m) {
		P[0] = 1;
		for (int i = 1; i < n; ++i) {
			P[i] = 131 * P[i - 1] % mod;
		}
		for (int i = 0; i < n; ++i) {
			Q[i] = ((i ? Q[i - 1] : 0) + P[i]) % mod;
		}
		R[n - 1] = pow(P[n - 1], mod - 2, mod);
		for (int i = n - 2; i >= 0; --i) {
			R[i] = 131 * R[i + 1] % mod;
		}
	}
	LzSeg(string &s, T m) : LzSeg(s.size(), m) {
		build(s, 1, 0, n - 1);
	}
	void update(int i, int j, T val) {
		update(1, 0, n - 1, i, j, val);
	}
	T hash(int i, int j) {
		T ret = hash(1, 0, n - 1, i, j);
		ret = ret * R[i] % mod;
		return ret;
	}
private:
	void build(string &s, int p, int l, int r) {
		if (l == r) {
			st[p] = P[l] * s[l] % mod;
			return;
		}
		int m = (l + r) / 2;
		build(s, 2 * p, l, m);
		build(s, 2 * p + 1, m + 1, r);
		st[p] = (st[2 * p] + st[2 * p + 1]) % mod;
	}
	void propagate(int p, int l, int r) {
		if (lz[p] == 0) {
			return;
		}
		st[p] = ((Q[r] - (l ? Q[l - 1] : 0) + mod) * lz[p]) % mod;
		if (l != r) {
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
		st[p] = (st[2 * p] + st[2 * p + 1]) % mod;
	}
	T hash(int p, int l, int r, int i, int j) {
		propagate(p, l, r);
		if (r < i || j < l) {
			return 0;
		} else if (i <= l && r <= j) {
			return st[p];
		}
		int m = (l + r) / 2;
		return (hash(2 * p, l, m, i, j) + hash(2 * p + 1, m + 1, r, i, j)) % mod;
	}
	int n;
	vector<T> st, lz, P, Q, R;
	T mod;
};

ll _hash(string &S, ll mod) {
	ll ret{};
	for (int i = S.size() - 1; i >= 0; --i) {
		ret = (131 * ret + S[i]) % mod;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	set<ii> B;
	for (int i = 0; i < N; ++i) {
		B.insert({_hash(A[i], mod1), _hash(A[i], mod2)});
	}
	LzSeg seg1(S, mod1);
	LzSeg seg2(S, mod2);
	int Q{};
	cin >> Q;
	while (Q--) {
		int q{}, l{}, r{};
		cin >> q >> l >> r;
		--l, --r;
		if (q == 1) {
			char c{};
			cin >> c;
			seg1.update(l, r, c);
			seg2.update(l, r, c);
		} else {
			ll h1 = seg1.hash(l, r);
			ll h2 = seg2.hash(l, r);
			cout << B.count({h1, h2}) << "\n";
		}
	}
	return 0;
}
