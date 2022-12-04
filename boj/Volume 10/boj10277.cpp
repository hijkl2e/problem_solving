#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using query = tuple<int, int, int, int>;

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
	vector<query> A(O);
	vector<int> B;
	for (auto &[a, b, c, d] : A) {
		string cmd;
		cin >> cmd >> b;
		c = b;
		B.push_back(b);
		if (cmd == "state") {
			a = 2;
			continue;
		}
		a = 1;
		if (cmd == "groupchange") {
			cin >> c;
			B.push_back(c);
		}
		cin >> d;
	}
	sort(B.begin(), B.end());
	B.resize(unique(B.begin(), B.end()) - B.begin());
	for (auto &[a, b, c, d] : A) {
		b = lower_bound(B.begin(), B.end(), b) - B.begin();
		c = lower_bound(B.begin(), B.end(), c) - B.begin();
	}
	LzSeg<int> seg1(B.size());
	LzSeg<int> seg2(B.size());
	for (auto &[a, b, c, d] : A) {
		int ans{};
		if (a == 1) {
			if (d > 0) {
				ans = min(d, N + seg2.rmq(b, c));
			} else {
				ans = max(d, -seg1.rmq(b, c));
			}
			seg1.update(b, c, ans);
			seg2.update(b, c, -ans);
		} else {
			ans = seg1.rmq(b, b);
		}
		cout << ans << "\n";
	}
	return 0;
}
