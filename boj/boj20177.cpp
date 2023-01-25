#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using query = tuple<int, int, ll, int>;

template <typename T = ll>
class Seg {
public:
	Seg(int sz) : n(sz), st(2 * sz) { }
	void update(int p, T val) {
		p += n;
		for (st[p] = max(st[p], val); p > 1; p /= 2) {
			st[p / 2] = max(st[p], st[p ^ 1]);
		}
	}
	int query(int l, int r, T val) {
		int L = -1, R = -1;
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if ((l & 1) && st[l++] >= val) {
				L = l - 1;
			}
			if ((r & 1) && st[--r] >= val) {
				R = max(R, r);
			}
		}
		if (L == -1 && R == -1) {
			return -1;
		}
		int p = R == -1 ? L : R;
		while (p < n) {
			p = 2 * p + (st[2 * p + 1] >= val);
		}
		return p - n;
	}
private:
	int n;
	vector<T> st;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ll> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<ll> psum(N + 1);
	partial_sum(A.begin(), A.end(), psum.begin());
	vector<query> B(M);
	for (int i = 0; i < M; ++i) {
		auto &[e, s, u, idx] = B[i];
		cin >> s >> e >> u;
		idx = i;
	}
	sort(B.begin(), B.end());
	vector<ll> C;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < i; ++j) {
			C.push_back(psum[i] - psum[j]);
		}
	}
	sort(C.begin(), C.end());
	C.resize(unique(C.begin(), C.end()) - C.begin());
	for (auto &[e, s, u, idx] : B) {
		u = upper_bound(C.begin(), C.end(), u) - C.begin() - 1;
	}
	Seg seg(C.size());
	vector<ll> D(M);
	for (int i = 0, j = 0; i < M; ++i) {
		auto &[e, s, u, idx] = B[i];
		while (j < e) {
			for (int k = ++j; k > 0; --k) {
				int idx = lower_bound(C.begin(), C.end(), psum[j] - psum[k - 1]) - C.begin();
				seg.update(idx, k);
			}
		}
		D[idx] = seg.query(0, u + 1, s);
	}
	for (int i = 0; i < M; ++i) {
		if (D[i] == -1) {
			cout << "NONE\n";
		} else {
			cout << C[D[i]] << "\n";
		}
	}
	return 0;
}
