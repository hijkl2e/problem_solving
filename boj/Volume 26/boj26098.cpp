#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using iii = tuple<int, int, int>;

const ll MOD = 1e9 + 7;

template <typename T = ll>
class Seg {
public:
	Seg(int sz) : n(sz), st(2 * sz) { }
	Seg(vector<T> &A) : n(A.size()), st(2 * A.size()) {
		copy(A.begin(), A.end(), st.begin() + n);
		for (int i = n - 1; i > 0; --i) {
			st[i] = st[2 * i] | st[2 * i + 1];
		}
	}
	T query(int l, int r) {
		T ret{};
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) {
				ret = ret | st[l++];
			}
			if (r & 1) {
				ret = st[--r] | ret;
			}
		}
		return ret;
	}
private:
	int n;
	vector<T> st;
};

template <typename T = ll>
class FT {
public:
	FT(int n) : ft(n + 1) { }
	T rsq(int j) {
		T res{};
		while (j) {
			res += ft[j];
			j -= LSOne(j);
		}
		return res % MOD;
	}
	void update(int i, T v) {
		while (i < ft.size()) {
			ft[i] += v;
			i += LSOne(i);
		}
	}
private:
	T LSOne(T x) {
		return x & -x;
	}
	vector<T> ft;
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
	vector<int> L(N + 1);
	stack<int> st;
	for (int i = N; i > 0; --i) {
		while (st.size() && A[st.top()] < A[i]) {
			L[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while (st.size()) {
		st.pop();
	}
	Seg seg(A);
	vector<iii> B;
	for (int i = 1; i <= N; ++i) {
		while (st.size() && A[st.top()] < A[i]) {
			int j = st.top(); st.pop();
			if (L[j]) {
				ll res = (A[L[j]] & A[i]) - seg.query(L[j] + 1, i);
				if (res > 0) {
					B.push_back({-L[j], i, res % MOD});
				}
			}
		}
		if (st.empty() || A[st.top()] > A[i]) {
			st.push(i);
		}
	}
	sort(B.begin(), B.end());
	int Q{};
	cin >> Q;
	vector<iii> C(Q);
	for (int i = 0; i < Q; ++i) {
		auto &[l, r, idx] = C[i];
		cin >> l >> r;
		l = -l;
		idx = i;
	}
	sort(C.begin(), C.end());
	FT ft(N);
	vector<int> ans(Q);
	for (int i = 0, j = 0; i < Q; ++i) {
		auto &[l1, r1, idx] = C[i];
		while (j < B.size()) {
			auto &[l2, r2, res] = B[j];
			if (l1 < l2) {
				break;
			}
			ft.update(r2, res);
			++j;
		}
		ans[idx] = ft.rsq(r1);
	}
	for (int i = 0; i < Q; ++i) {
		cout << ans[i] << "\n";
	}
	return 0;
}
