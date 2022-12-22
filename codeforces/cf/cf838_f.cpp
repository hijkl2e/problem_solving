#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9 + 7;

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

template <typename T = ll>
class FT {
public:
	FT(int n) : ft(n + 1) { }
	T rsq(int i, int j) {
		return rsq(j) - rsq(i - 1);
	}
	T rsq(int j) {
		T res{};
		while (j) {
			res += ft[j];
			j -= LSOne(j);
		}
		return res;
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

int N, K;
Seg seg(200005);
FT ft(200005);

ll solve(vector<int> &A) {
	ll ret{};
	vector<int> dp(N);
	for (int i = N - 1; i >= 0; --i) {
		int j = seg.rmq(A[i] + 1, A[i] + K + 1);
		if (j < N) {
			dp[i] = dp[j] + ft.rsq(A[i] + 1, A[j]);
		}
		ret += dp[i];
		seg.update(A[i], i);
		ft.update(A[i], 1);
	}
	for (int x : A) {
		seg.update(x, INF);
		ft.update(x, -1);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		cin >> N >> K;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		ll ans{};
		map<int, int> freq;
		for (int x : A) {
			ans += ++freq[x];
		}
		ans += solve(A);
		reverse(A.begin(), A.end());
		ans += solve(A);
		cout << ans << "\n";
	}
	return 0;
}
