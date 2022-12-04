#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using li = pair<ll, int>;
using query = tuple<ll, int, int, int>;

const ll INF = 4e18;

template <typename T = ll>
class Seg {
public:
	Seg(int sz) : n(sz), st(2 * sz, INF) { }
	void update(int p, T val) {
		for (st[p += n] = val; p > 1; p /= 2) {
			st[p / 2] = min(st[p], st[p ^ 1]);
		}
	}
	T rmq(int l, int r) {
		T ret = INF;
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) {
				ret = min(ret, st[l++]);
			}
			if (r & 1) {
				ret = min(st[--r], ret);
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
	vector<ll> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<ll> psum(N + 1);
	partial_sum(A.begin(), A.end(), psum.begin());
	vector<li> B(N);
	for (int i = 0; i < N; ++i) {
		B[i] = {2 * psum[i + 1], i + 1};
	}
	sort(B.begin(), B.end());
	int Q{};
	cin >> Q;
	vector<query> C(Q);
	for (int i = 0; i < Q; ++i) {
		auto &[sum, l, r, idx] = C[i];
		cin >> l >> r;
		sum = psum[l - 1] + psum[r];
		idx = i;
	}
	sort(C.begin(), C.end());
	vector<ll> ans(Q, INF);
	for (int k = 0; k < 2; ++k) {
		Seg seg(N + 1);
		for (int i = 0, j = 0; i < Q; ++i) {
			auto &[sum, l, r, i1] = C[i];
			while (j < B.size()) {
				auto &[val, i2] = B[j];
				if ((val <= sum) ^ k) {
					seg.update(i2, val * (k ? 1 : -1));
					++j;
				} else {
					break;
				}
			}
			int len = (r - l + 1) / 3;
			ans[i1] = min(ans[i1], seg.rmq(l + len - 1, r - len + 1) + sum * (k ? -1 : 1));
		}
		reverse(B.begin(), B.end());
		reverse(C.begin(), C.end());
	}
	for (ll x : ans) {
		cout << x << "\n";
	}
	return 0;
}
