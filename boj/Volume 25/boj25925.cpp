#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using iii = tuple<int, int, int>;

const ll INF = 4e18;

template <typename T = ll>
class Seg {
public:
	Seg(int sz) : n(sz), st(2 * sz) { }
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
	int N{}, Q{};
	cin >> N >> Q;
	vector<iii> A(N);
	for (int i = 0; i < N; ++i) {
		auto &[y, x, idx] = A[i];
		cin >> x >> y;
		idx = i + 1;
	}
	sort(A.begin(), A.end());
	vector<int> B(N);
	vector<int> C(N);
	for (int i = 0; i < N; ++i) {
		auto &[y, x, idx] = A[i];
		B[i] = x + y;
		C[i] = x - y;
	}
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());
	B.resize(unique(B.begin(), B.end()) - B.begin());
	C.resize(unique(C.begin(), C.end()) - C.begin());
	Seg seg1(B.size());
	Seg seg2(C.size());
	vector<int> ans(N + 1);
	for (auto &[y, x, idx] : A) {
		int u = lower_bound(B.begin(), B.end(), x + y) - B.begin();
		int v = lower_bound(C.begin(), C.end(), x - y) - C.begin();
		ans[idx] = max(seg1.rmq(u, B.size()), seg2.rmq(0, v + 1)) + 1;
		seg1.update(u, ans[idx]);
		seg2.update(v, ans[idx]);
	}
	while (Q--) {
		int q{};
		cin >> q;
		cout << ans[q] << "\n";
	}
	return 0;
}
