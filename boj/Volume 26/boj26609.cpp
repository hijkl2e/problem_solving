#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

template <typename T = ll>
class Seg {
public:
	Seg() { }
	Seg(int sz) : n(sz), st(2 * sz) { }
	Seg(vector<T> &A) : n(A.size()), st(2 * A.size()) {
		copy(A.begin(), A.end(), st.begin() + n);
		for (int i = n - 1; i > 0; --i) {
			st[i] = min(st[2 * i], st[2 * i + 1]);
		}
	}
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

vector<ll> A;
Seg<ll> seg1, seg2;
vector<vector<ll>> dp;

void solve(int L, int R, int optL, int optR) {
	if (L > R) {
		return;
	}
	int j = (L + R) / 2;
	dp[1][j] = -INF;
	int opt{};
	ll minv{}, maxv{};
	for (int k = min(optR, j); k >= optL; --k) {
		if (k == min(optR, j)) {
			minv = seg1.rmq(k + 1, j + 1);
			maxv = -seg2.rmq(k + 1, j + 1);
		}
		minv = min(minv, A[k]);
		maxv = max(maxv, A[k]);
		ll val = max(dp[0][k], 1LL) * (maxv - minv);
		if (dp[1][j] < val) {
			dp[1][j] = val;
			opt = k;
		}
	}
	solve(L, j - 1, optL, opt);
	solve(j + 1, R, opt, optR);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	A.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	partial_sum(A.begin(), A.end(), A.begin());
	seg1 = Seg(A);
	vector<ll> B(N + 1);
	for (int i = 1; i <= N; ++i) {
		B[i] = -A[i];
	}
	seg2 = Seg(B);
	dp.assign(2, vector<ll>(N + 1));
	for (int i = 1; i <= K; ++i) {
		solve(0, N, 0, N);
		copy(dp[1].begin(), dp[1].end(), dp[0].begin());
	}
	cout << dp[0][N] << "\n";
	return 0;
}
