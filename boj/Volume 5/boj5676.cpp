#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
class Seg {
public:
	Seg(int sz) : n(sz), st(2 * sz) { }
	Seg(vector<T> &A) : n(A.size()), st(2 * A.size()) {
		copy(A.begin(), A.end(), st.begin() + n);
		for (int i = n - 1; i > 0; --i) {
			st[i] = st[2 * i] * st[2 * i + 1];
		}
	}
	void update(int p, T val) {
		for (st[p += n] = val; p > 1; p /= 2) {
			st[p / 2] = st[p] * st[p ^ 1];
		}
	}
	T rmq(int l, int r) {
		T ret = 1;
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) {
				ret = ret * st[l++];
			}
			if (r & 1) {
				ret = st[--r] * ret;
			}
		}
		return ret;
	}
private:
	int n;
	vector<T> st;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	while (cin >> N >> K) {
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		for (int i = 0; i < N; ++i) {
			A[i] = A[i] > 0 ? 1 : A[i] < 0 ? -1 : 0;
		}
		Seg seg(A);
		while (K--) {
			char c{};
			int a{}, b{};
			cin >> c >> a >> b;
			if (c == 'C') {
				seg.update(a - 1, b > 0 ? 1 : b < 0 ? -1 : 0);
			} else {
				int res = seg.rmq(a - 1, b);
				cout << (res == 1 ? '+' : res == -1 ? '-' : '0');
			}
		}
		cout << "\n";
	}
	return 0;
}
