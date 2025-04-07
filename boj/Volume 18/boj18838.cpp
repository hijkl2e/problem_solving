#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using iii = tuple<int, int, ll>;

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<ii> B(N);
	for (int i = 0; i < N; ++i) {
		B[i] = {A[i], i};
	}
	sort(B.rbegin(), B.rend());
	vector<int> L(N);
	Seg seg(N);
	for (int i = 0; i < N; ++i) {
		int x = B[i].second;
		L[x] = seg.rmq(x, N) + 1;
		seg.update(x, L[x]);
	}
	int maxl = *max_element(L.begin(), L.end());
	vector<ll> C(N);
	vector<vector<int>> D(maxl + 1);
	for (int i = 0; i < N; ++i) {
		int x = B[i].second;
		D[L[x]].push_back(x);
	}
	FT<__int128> ft(N);
	for (int x : D[1]) {
		C[x] = 1;
	}
	for (int i = 2; i < D.size(); ++i) {
		int k{};
		for (int j = 0; j < D[i].size(); ++j) {
			while (k < D[i - 1].size() && A[D[i][j]] < A[D[i - 1][k]]) {
				int x = D[i - 1][k++];
				ft.update(N - x, C[x]);
			}
			int y = D[i][j];
			C[y] = min<__int128>(ft.rsq(N - y), INF);
		}
		while (k--) {
			int x = D[i - 1][k];
			ft.update(N - x, -C[x]);
		}
	}
	vector<vector<iii>> E(maxl + 1);
	for (int i = 0; i < N; ++i) {
		E[L[i]].push_back({A[i], i, C[i]});
	}
	for (int i = 1; i < E.size(); ++i) {
		sort(E[i].begin(), E[i].end());
	}
	vector<int> F;
	for (int i = maxl; i > 0; --i) {
		for (auto &[a, b, c] : E[i]) {
			if (F.size() && F.back() > a) {
				continue;
			} else if (K > c) {
				K -= c;
			} else {
				F.push_back(a);
				break;
			}
		}
	}
	if (F.size() == maxl) {
		for (int i = 0; i < maxl; ++i) {
			cout << F[i] << (i == maxl - 1 ? "\n" : " ");
		}
	} else {
		cout << "-1\n";
	}
	return 0;
}
