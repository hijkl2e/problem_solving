#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;
using rec = tuple<int, int, int, int>;

const int INF = 1e9 + 7;

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
		return {max(l1, s1 + l2), max(r2, s2 + r1), max({t1, t2, r1 + l2}), s1 + s2};
	}
	int n;
	vector<rec> st;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n1{};
	cin >> n1;
	vector<iii> A(n1);
	for (auto &[x, y, w] : A) {
		cin >> x >> y;
	}
	int n2{};
	cin >> n2;
	vector<iii> B(n2);
	for (auto &[x, y, w] : B) {
		cin >> x >> y;
	}
	int c1{}, c2{};
	cin >> c1 >> c2;
	for (auto &[x, y, w] : A) {
		w = c1;
	}
	for (auto &[x, y, w] : B) {
		w = -c2;
	}
	copy(B.begin(), B.end(), back_inserter(A));
	sort(A.begin(), A.end());
	vector<int> C(A.size());
	for (int i = 0; i < C.size(); ++i) {
		C[i] = get<1>(A[i]);
	}
	sort(C.begin(), C.end());
	C.resize(unique(C.begin(), C.end()) - C.begin());
	for (auto &[x, y, w] : A) {
		y = lower_bound(C.begin(), C.end(), y) - C.begin();
	}
	int ans{};
	for (int z = 0; z < A.size(); ++z) {
		if (z && get<0>(A[z - 1]) == get<0>(A[z])) {
			continue;
		}
		vector<int> D(C.size());
		Seg seg(1 << 11);
		for (int i = z, j = z + 1; i < A.size(); i = j++) {
			while (j < A.size() && get<0>(A[i]) == get<0>(A[j])) {
				++j;
			}
			for (int k = i; k < j; ++k) {
				auto &[x, y, w] = A[k];
				D[y] += w;
				seg.update(y, D[y]);
			}
			ans = max(ans, seg.query());
		}
	}
	cout << ans << "\n";
	return 0;
}
