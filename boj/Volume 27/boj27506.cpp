#include <bits/stdc++.h>

using namespace std;

class Seg {
public:
	Seg(int sz) : n(sz), st(2 * sz, vector<int>(5)) { }
	Seg(vector<vector<int>> &A) : n(A.size()), st(2 * A.size(), vector<int>(5)) {
		copy(A.begin(), A.end(), st.begin() + n);
		for (int i = n - 1; i > 0; --i) {
			conquer(st[i], st[2 * i], st[2 * i + 1]);
		}
	}
	void update(int p, vector<int> &A) {
		for (st[p + n] = A, p = (p + n) / 2; p > 0; p /= 2) {
			conquer(st[p], st[2 * p], st[2 * p + 1]);
		}
	}
	vector<int> query(int l, int r) {
		static vector<int> L(5);
		static vector<int> R(5);
		static vector<int> T(5);
		for (int i = 0; i < 5; ++i) {
			L[i] = R[i] = i;
		}
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) {
				conquer(T, L, st[l++]);
				swap(L, T);
			}
			if (r & 1) {
				conquer(T, st[--r], R);
				swap(R, T);
			}
		}
		conquer(T, L, R);
		return T;
	}
private:
	void conquer(vector<int> &A, vector<int> &B, vector<int> &C) {
		for (int i = 0; i < 5; ++i) {
			A[i] = B[C[i]];
		}
	}
	int n;
	vector<vector<int>> st;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(5));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> A[i][j];
			--A[i][j];
		}
	}
	Seg seg(A);
	vector<int> y(5);
	vector<int> z(5);
	int Q{};
	cin >> Q;
	while (Q--) {
		int u{}, a{}, b{};
		cin >> u >> a >> b;
		for (int i = 0; i < 5; ++i) {
			cin >> y[i];
			--y[i];
		}
		vector<int> f = seg.query(a - 1, u - 1);
		vector<int> g = seg.query(u, b);
		for (int i = 0; i < 5; ++i) {
			z[g[i]] = find(f.begin(), f.end(), y[i]) - f.begin();
		}
		for (int i = 0; i < 5; ++i) {
			cout << z[i] + 1 << (i == 4 ? "\n" : " ");
		}
		seg.update(u - 1, z);
	}
	return 0;
}
