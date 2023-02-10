#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;
const double EPS = 1e-9;

struct line {
	ll a{}, b{};
	double c{};
};

double get_x(line &l1, line &l2) {
	return (l1.b - l2.b) * 1.0 / (l2.a - l1.a);
}

class Seg {
public:
	Seg(vector<line> &A) : n(A.size()), st(2 * A.size()) {
		for (int i = 0; i < n; ++i) {
			st[i + n].push_back(A[i]);
		}
		for (int i = n - 1; i > 0; --i) {
			int l = 2 * i;
			int r = 2 * i + 1;
			copy(st[l].begin(), st[l].end(), back_inserter(st[i]));
			for (auto L : st[r]) {
				while (st[i].size()) {
					L.c = get_x(L, st[i].back());
					if (L.c < st[i].back().c - EPS) {
						st[i].pop_back();
					} else {
						break;
					}
				}
				st[i].push_back(L);
			}
		}
	}
	ll query(int l, int r, ll x) {
		ll ret = INF;
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) {
				ret = min(ret, query(l++, x));
			}
			if (r & 1) {
				ret = min(query(--r, x), ret);
			}
		}
		return ret;
	}
private:
	ll query(int p, ll x) {
		int lo = 0, hi = st[p].size();
		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;
			if (st[p][mid].c - EPS < x) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		return st[p][lo].a * x + st[p][lo].b;
	}
	int n;
	vector<vector<line>> st;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	vector<ll> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	partial_sum(A.begin(), A.end(), A.begin());
	vector<line> B(N + 1);
	for (int i = 0; i <= N; ++i) {
		B[i] = {-i, A[i], -INF};
	}
	Seg seg1(B);
	for (int i = 0; i <= N; ++i) {
		B[i] = {-i, -A[i], -INF};
	}
	Seg seg2(B);
	while (Q--) {
		int a{}, b{}, c{}, d{};
		cin >> a >> b >> c >> d;
		int lo = 1, hi = 1e8 + 1;
		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;
			if (-seg2.query(c, d + 1, -mid) >= seg1.query(a - 1, b, mid)) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		cout << lo << "\n";
	}
	return 0;
}
