#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

class Seg {
public:
	Seg(int sz) : n(sz), st(2 * sz) { }
	Seg(vector<int> &A) : n(A.size()), st(2 * A.size()) {
		for (int i = 0; i < n; ++i) {
			st[n + i].first = A[i];
		}
		for (int i = n - 1; i > 0; --i) {
			st[i] = conquer(st[2 * i], st[2 * i + 1]);
		}
	}
	void update(int p, int val) {
		for (st[p += n].first = val; p > 1; p /= 2) {
			st[p / 2] = conquer(st[p], st[p ^ 1]);
		}
	}
	ii query(int l, int r) {
		ii ret;
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) {
				ret = conquer(ret, st[l++]);
			}
			if (r & 1) {
				ret = conquer(st[--r], ret);
			}
		}
		return ret;
	}
private:
	ii conquer(ii &a, ii &b) {
		static vector<int> A(4);
		A[0] = a.first, A[1] = a.second;
		A[2] = b.first, A[3] = b.second;
		sort(A.rbegin(), A.rend());
		return {A[0], A[1]};
	}
	int n;
	vector<ii> st;
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
		int q{}, a{}, b{};
		cin >> q >> a >> b;
		if (q == 1) {
			seg.update(a - 1, b);
		} else {
			auto res = seg.query(a - 1, b);
			cout << res.first + res.second << "\n";
		}
	}
	return 0;
}
