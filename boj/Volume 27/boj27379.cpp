#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

template <typename T = ll>
class Seg {
public:
	Seg(int sz) : n(sz), st(2 * sz) { }
	Seg(vector<T> &A) : n(A.size()), st(2 * A.size()) {
		copy(A.begin(), A.end(), st.begin() + n);
		for (int i = n - 1; i > 0; --i) {
			st[i] = max(st[2 * i], st[2 * i + 1]);
		}
	}
	void update(int p, T val) {
		for (st[p += n] = val; p > 1; p /= 2) {
			st[p / 2] = max(st[p], st[p ^ 1]);
		}
	}
	T rmq(int l, int r) {
		T ret = -INF;
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) {
				ret = max(ret, st[l++]);
			}
			if (r & 1) {
				ret = max(st[--r], ret);
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
	cin >> N >> K;
	vector<ll> A(2 * N + 1);
	vector<int> B(2 * N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	for (int i = 1; i <= N; ++i) {
		cin >> B[i];
	}
	for (int i = N + 1; i <= 2 * N; ++i) {
		A[i] = A[i - N];
		B[i] = B[i - N];
	}
	vector<ll> C(2 * N + 1);
	partial_sum(A.begin(), A.end(), C.begin());
	Seg seg(C);
	ll ans = -INF;
	int cnt{};
	for (int i = 1, j = 0; i <= N; ++i) {
		if (B[i - 1]) {
			--cnt;
		}
		while (cnt < K) {
			if (B[++j]) {
				++cnt;
			}
		}
		ans = max(ans, seg.rmq(j, i + N) - C[i - 1]);
	}
	cout << ans << "\n";
	return 0;
}
