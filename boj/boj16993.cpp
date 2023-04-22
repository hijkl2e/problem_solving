#include <bits/stdc++.h>

using namespace std;

using rec = tuple<int, int, int, int>;

const int INF = 1e9 + 7;

class Seg {
public:
	Seg(int sz) : n(sz), st(2 * sz) { }
	Seg(vector<int> &A) : n(A.size()), st(2 * A.size()) {
		for (int i = 0; i < n; ++i) {
			st[n + i] = {A[i], A[i], A[i], A[i]};
		}
		for (int i = n - 1; i > 0; --i) {
			st[i] = conquer(st[2 * i], st[2 * i + 1]);
		}
	}
	int rmq(int l, int r) {
		rec L{-INF, -INF, -INF, -INF};
		rec R{-INF, -INF, -INF, -INF};
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) {
				L = conquer(L, st[l++]);
			}
			if (r & 1) {
				R = conquer(st[--r], R);
			}
		}
		return get<2>(conquer(L, R));
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
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	Seg seg(A);
	int M{};
	cin >> M;
	while (M--) {
		int s{}, e{};
		cin >> s >> e;
		cout << seg.rmq(s - 1, e) << "\n";
	}
	return 0;
}
