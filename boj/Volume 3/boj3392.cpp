#include <bits/stdc++.h>

using namespace std;

using rec = tuple<int, int, int, int>;

class Seg {
public:
	Seg(int sz) : n(sz), st1(4 * sz), st2(4 * sz) { }
	void update(int i, int j, int val) {
		update(1, 0, n - 1, i, j, val);
	}
	int query() {
		return st2[1];
	}
private:
	void update(int p, int l, int r, int i, int j, int val) {
		if (r < i || j < l) {
			return;
		} else if (i <= l && r <= j) {
			st1[p] += val;
		} else {
			int m = (l + r) / 2;
			update(2 * p, l, m, i, j, val);
			update(2 * p + 1, m + 1, r, i, j, val);
		}
		if (st1[p]) {
			st2[p] = r - l + 1;
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
	while (N--) {
		int x1{}, y1{}, x2{}, y2{};
		cin >> x1 >> y1 >> x2 >> y2;
		A.push_back({x1, y1, y2, 1});
		A.push_back({x2, y1, y2, -1});
	}
	sort(A.begin(), A.end());
	Seg seg(30001);
	int ans{}, p{};
	for (auto &[x, y1, y2, z] : A) {
		ans += (x - p) * seg.query();
		seg.update(y1, y2 - 1, z);
		p = x;
	}
	cout << ans << "\n";
	return 0;
}
