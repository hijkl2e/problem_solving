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
	int N{};
	cin >> N;
	vector<ll> A(N);
	vector<ll> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
	}
	Seg seg(B);
	int M{};
	cin >> M;
	while (M--) {
		int x{}, y{};
		cin >> x >> y;
		int l = lower_bound(A.begin(), A.end(), x) - A.begin();
		int r = upper_bound(A.begin(), A.end(), y) - A.begin() - 1;
		int ans = r - l == y - x ? 1 : -1;
		bool yes = true;
		if (A[l] == x && A[r] == y) {
			yes &= B[l] >= B[r];
		}
		ll maxv = A[r] == y ? B[r] : B[l];
		if ((A[l] == x) ^ (A[r] == y)) {
			if (A[l] == x) {
				++r;
			} else {
				--l;
			}
		}
		if (A[l] == x || A[r] == y) {
			yes &= l + 1 == r || seg.rmq(l + 1, r) < maxv;
		}
		ans *= yes;
		cout << (ans == 1 ? "true" : ans == 0 ? "false" : "maybe") << "\n";
	}
	return 0;
}
