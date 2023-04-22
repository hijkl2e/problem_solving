#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using rec = tuple<int, int, int, int>;

class Seg {
public:
	Seg(int sz) : n(sz), st1(4 * sz), st2(4 * sz) { }
	void update(int i, int j, int val, vector<int> &B) {
		update(1, 0, n - 1, i, j, val, B);
	}
	int query() {
		return st2[1];
	}
private:
	void update(int p, int l, int r, int i, int j, int val, vector<int> &B) {
		if (r < i || j < l) {
			return;
		} else if (i <= l && r <= j) {
			st1[p] += val;
		} else {
			int m = (l + r) / 2;
			update(2 * p, l, m, i, j, val, B);
			update(2 * p + 1, m + 1, r, i, j, val, B);
		}
		if (st1[p]) {
			st2[p] = B[r + 1] - B[l];
		} else {
			st2[p] = l == r ? 0 : (st2[2 * p] + st2[2 * p + 1]);
		}
	}
	int n;
	vector<int> st1, st2;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<rec> A;
	vector<int> B;
	while (N--) {
		int x1{}, x2{}, y1{}, y2{};
		cin >> x1 >> x2 >> y1 >> y2;
		A.push_back({x1, y1, y2, 1});
		A.push_back({x2, y1, y2, -1});
		B.push_back(y1);
		B.push_back(y2);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	B.resize(unique(B.begin(), B.end()) - B.begin());
	Seg seg(B.size());
	ll ans{}, p{};
	for (auto &[x, y1, y2, z] : A) {
		ans += (x - p) * seg.query();
		y1 = lower_bound(B.begin(), B.end(), y1) - B.begin();
		y2 = lower_bound(B.begin(), B.end(), y2) - B.begin() - 1;
		seg.update(y1, y2, z, B);
		p = x;
	}
	cout << ans << "\n";
	return 0;
}
