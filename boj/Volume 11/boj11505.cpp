#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

template <typename T = ll>
class Seg {
public:
	Seg(int sz) : n(sz), st(2 * sz) { }
	Seg(vector<T> &A) : n(A.size()), st(2 * A.size()) {
		copy(A.begin(), A.end(), st.begin() + n);
		for (int i = n - 1; i > 0; --i) {
			st[i] = st[2 * i] * st[2 * i + 1] % MOD;
		}
	}
	void update(int p, T val) {
		for (st[p += n] = val; p > 1; p /= 2) {
			st[p / 2] = st[p] * st[p ^ 1] % MOD;
		}
	}
	T rmq(int l, int r) {
		T ret = 1;
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) {
				ret = ret * st[l++] % MOD;
			}
			if (r & 1) {
				ret = st[--r] * ret % MOD;
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
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	Seg seg(A);
	M += K;
	while (M--) {
		int a{}, b{}, c{};
		cin >> a >> b >> c;
		--b;
		if (a == 1) {
			seg.update(b, A[b] = c);
		} else {
			cout << seg.rmq(b, c) << "\n";
		}
	}
	return 0;
}
