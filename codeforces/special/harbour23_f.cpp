#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;
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
	int N{}, Q{};
	cin >> N >> Q;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<iii> B(Q);
	for (int i = 0; i < Q; ++i) {
		auto &[l, r, idx] = B[i];
		cin >> l >> r;
		idx = i;
	}
	sort(B.begin(), B.end());
	vector<vector<int>> C(N + 1);
	for (int i = 0; i < N; ++i) {
		C[A[i]].push_back(i);
	}
	deque<ii> D;
	Seg seg(N);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j < C[i].size(); ++j) {
			int res = seg.rmq(C[i][j - 1], C[i][j]);
			D.push_back({res, i});
		}
		for (int j = 0; j < C[i].size(); ++j) {
			seg.update(C[i][j], i);
		}
	}
	sort(D.begin(), D.end());
	FT ft(N);
	for (int i = 0; i < N; ++i) {
		ft.update(A[i], 1);
	}
	vector<int> E(Q);
	for (int i = 0, j = 1; i < Q; i = j++) {
		while (j < Q && get<0>(B[i]) == get<0>(B[j])) {
			++j;
		}
		while (D.size() && D.front().first < get<0>(B[i])) {
			auto [u, v] = D.front();
			D.pop_front();
			ft.update(v, -1);
		}
		for (int k = i; k < j; ++k) {
			auto &[l, r, idx] = B[k];
			E[idx] = ft.rsq(l, r);
		}
	}
	for (int i = 0; i < Q; ++i) {
		cout << E[i] << "\n";
	}
	return 0;
}
