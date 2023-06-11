#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, ll>;
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
		res = min<T>(res, INF);
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
		B[i] = {-A[i], i};
	}
	sort(B.begin(), B.end());
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
			C[y] = ft.rsq(N - y);
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
	vector<ii> G;
	G.push_back({1, 1});
	ft.update(1, 1);
	for (int i = maxl; i > 0; --i) {
		for (int j = 0, k = 1; j < E[i].size(); j = k++) {
			if (F.size() && F.back() >= get<0>(E[i][j])) {
				continue;
			}
			while (k < E[i].size()) {
				if (get<0>(E[i][j]) == get<0>(E[i][k])) {
					++k;
				} else {
					break;
				}
			}
			__int128 sum{};
			for (int l = j; l < k; ++l) {
				auto &[a, b, c] = E[i][l];
				sum += min<__int128>(ft.rsq(b + 1) * c, INF);
			}
			if (K > sum) {
				K -= sum;
				continue;
			}
			F.push_back(get<0>(E[i][j]));
			vector<ii> H;
			for (int l = k - 1; l >= j; --l) {
				auto &[a, b, c] = E[i][l];
				ll x = ft.rsq(b + 1);
				H.push_back({b + 1, x});
				ft.update(b + 1, x);
			}
			for (auto &[u, v] : G) {
				ft.update(u, -v);
			}
			swap(G, H);
			break;
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
