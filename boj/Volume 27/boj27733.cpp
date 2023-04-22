#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

const ll INF = 4e18;

template <typename T = ll>
class LzSeg {
public:
	LzSeg(int sz) : n(sz), st1(sz), st2(4 * sz, -INF), lz(4 * sz), pq(sz) {
		for (int i = 0; i < n; ++i) {
			pq[i].push({INF, -1});
		}
	}
	void add(int i, ii val) {
		add(1, 0, n - 1, i, val);
	}
	void update(int i, int j, T val) {
		update(1, 0, n - 1, i, j, val);
	}
	vector<T> query(int i, int j) {
		A.clear();
		query(1, 0, n - 1, i, j);
		sort(A.begin(), A.end());
		return A;
	}
private:
	void propagate(int p, int l, int r) {
		if (lz[p] == 0) {
			return;
		}
		st2[p] += lz[p];
		if (l == r) {
			st1[l] += lz[p];
		} else {
			lz[2 * p] += lz[p];
			lz[2 * p + 1] += lz[p];
		}
		lz[p] = 0;
	}
	void add(int p, int l, int r, int i, ii val) {
		propagate(p, l, r);
		if (r < i || i < l) {
			return;
		} else if (l == r) {
			val.first += st1[l];
			pq[l].push(val);
			st2[p] = st1[l] - pq[l].top().first;
			return;
		}
		int m = (l + r) / 2;
		add(2 * p, l, m, i, val);
		add(2 * p + 1, m + 1, r, i, val);
		st2[p] = max(st2[2 * p], st2[2 * p + 1]);
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
		st2[p] = max(st2[2 * p], st2[2 * p + 1]);
	}
	void query(int p, int l, int r, int i, int j) {
		propagate(p, l, r);
		if (r < i || j < l || st2[p] < 0) {
			return;
		} else if (l == r) {
			while (st2[p] >= 0) {
				A.push_back(pq[l].top().second);
				pq[l].pop();
				st2[p] = st1[l] - pq[l].top().first;
			}
			return;
		}
		int m = (l + r) / 2;
		query(2 * p, l, m, i, j);
		query(2 * p + 1, m + 1, r, i, j);
		st2[p] = max(st2[2 * p], st2[2 * p + 1]);
	}
	int n;
	vector<T> st1, st2, lz, A;
	vector<priority_queue<ii, vector<ii>, greater<ii>>> pq;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, Q{};
	cin >> N >> Q;
	ll P{}, last{};
	LzSeg seg(N + 1);
	while (Q--) {
		ll q{}, x{}, y{};
		cin >> q >> x >> y;
		x ^= last;
		if (q == 1) {
			seg.add(x, {y, ++P});
			continue;
		}
		seg.update(x, N, y);
		vector<ll> A = seg.query(x, N);
		cout << A.size();
		for (ll z : A) {
			cout << " " << z;
		}
		cout << "\n";
		last = A.size();
	}
	return 0;
}
