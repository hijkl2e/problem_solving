#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using iii = tuple<int, int, int>;
using rec = tuple<ll, ll, ll, ll>;

class Seg {
public:
	Seg(int sz) : n(sz), st(2 * sz) { }
	void update(int p, ll val) {
		st[p += n] = {val, val, val, val};
		for (p /= 2; p > 0; p /= 2) {
			st[p] = conquer(st[2 * p], st[2 * p + 1]);
		}
	}
	ll query() {
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
	int N{};
	cin >> N;
	vector<iii> A(N);
	for (auto &[x, y, w] : A) {
		cin >> x >> y >> w;
	}
	sort(A.begin(), A.end());
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		B[i] = get<1>(A[i]);
	}
	sort(B.begin(), B.end());
	B.resize(unique(B.begin(), B.end()) - B.begin());
	for (auto &[x, y, w] : A) {
		y = lower_bound(B.begin(), B.end(), y) - B.begin();
	}
	ll ans{};
	for (int z = 0; z < N; ++z) {
		if (z && get<0>(A[z - 1]) == get<0>(A[z])) {
			continue;
		}
		vector<ll> C(B.size());
		Seg seg(1 << 12);
		for (int i = z, j = z + 1; i < N; i = j++) {
			while (j < N && get<0>(A[i]) == get<0>(A[j])) {
				++j;
			}
			for (int k = i; k < j; ++k) {
				auto &[x, y, w] = A[k];
				C[y] += w;
				seg.update(y, C[y]);
			}
			ans = max(ans, seg.query());
		}
	}
	cout << ans << "\n";
	return 0;
}
