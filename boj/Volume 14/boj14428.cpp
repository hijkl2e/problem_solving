#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
class Seg {
public:
	Seg(vector<T> &v) : n(v.size()), st(2 * v.size()), A(v) {
		for (int i = 0; i < n; ++i) {
			st[i + n] = i;
		}
		for (int i = n - 1; i > 0; --i) {
			st[i] = conquer(st[2 * i], st[2 * i + 1]);
		}
	}
	void update(int p, T val) {
		for (A[p] = val, p = (p + n) / 2; p > 0; p /= 2) {
			st[p] = conquer(st[2 * p], st[2 * p + 1]);
		}
	}
	int rmq(int l, int r) {
		int L = l, R = r - 1;
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) {
				L = conquer(L, st[l++]);
			}
			if (r & 1) {
				R = conquer(st[--r], R);
			}
		}
		return conquer(L, R);
	}
private:
	int conquer(int a, int b) {
		return A[a] <= A[b] ? a : b;
	}
	int n;
	vector<T> st, A;
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
		--a;
		if (q == 1) {
			seg.update(a, b);
		} else {
			cout << seg.rmq(a, b) + 1 << "\n";
		}
	}
	return 0;
}
