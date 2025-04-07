#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;
using rec = tuple<int, int, int, int>;

class Seg {
public:
	Seg(int sz) : n(sz), st(2 * sz) { }
	void update(int p, int val) {
		st[p += n] = {val, val, val, val};
		for (p /= 2; p > 0; p /= 2) {
			st[p] = conquer(st[2 * p], st[2 * p + 1]);
		}
	}
	int query() {
		return get<2>(st[1]);
	}
private:
	rec conquer(rec &L, rec &R) {
		auto &[l1, r1, t1, s1] = L;
		auto &[l2, r2, t2, s2] = R;
		return {max(l1, s1 ? s1 + l2 : 0), max(r2, s2 ? s2 + r1 : 0),
				max({t1, t2, r1 + l2}), s1 == s2 ? s1 + s2 : 0};
	}
	int n;
	vector<rec> st;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<iii> A;
	for (int i = 0; i < N; ++i) {
		int s{}, e{};
		cin >> s >> e;
		A.push_back({s, 1, i});
		A.push_back({e + 1, 0, i});
	}
	sort(A.begin(), A.end());
	Seg seg(1 << 17);
	int ans_x{}, ans_y{}, p{};
	for (auto &[t, z, i] : A) {
		int res = seg.query();
		if (ans_x == res) {
			ans_y += t - p;
		} else if (ans_x < res) {
			ans_x = res;
			ans_y = t - p;
		}
		seg.update(i, z);
		p = t;
	}
	cout << ans_x << " " << ans_y << "\n";
	return 0;
}
