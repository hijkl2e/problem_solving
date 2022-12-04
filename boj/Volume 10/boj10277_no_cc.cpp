#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9 + 7;

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
	int C{}, N{}, O{};
	cin >> C >> N >> O;
	LzSeg<int> seg1(C + 1);
	LzSeg<int> seg2(C + 1);
	while (O--) {
		string cmd;
		int a{}, b{}, c{}, ans{};
		cin >> cmd >> a;
		if (cmd == "state") {
			ans = seg1.rmq(a, a);
		} else {
			if (cmd == "change") {
				b = a;
			} else {
				cin >> b;
			}
			cin >> c;
			if (c > 0) {
				ans = min(c, N + seg2.rmq(a, b));
			} else {
				ans = max(c, -seg1.rmq(a, b));
			}
			seg1.update(a, b, ans);
			seg2.update(a, b, -ans);
		}
		cout << ans << "\n";
	}
	return 0;
}
