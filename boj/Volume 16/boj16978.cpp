#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using q1 = pair<int, int>;
using q2 = tuple<int, int, int, int>;

template <typename T = ll>
class FT {
public:
	FT(int n) : ft(n + 1) { }
	FT(vector<T> &A) : ft(A.size()) {
		for (int i = 1; i < ft.size(); ++i) {
			ft[i] += A[i];
			if (i + LSOne(i) < ft.size()) {
				ft[i + LSOne(i)] += ft[i];
			}
		}
	}
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
	int N{};
	cin >> N;
	vector<ll> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	FT ft(A);
	vector<q1> Q1;
	vector<q2> Q2;
	int M{};
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int q{}, a{}, b{}, c{};
		cin >> q >> a >> b;
		if (q == 1) {
			Q1.push_back({a, b});
		} else {
			cin >> c;
			Q2.push_back({a, b, c, Q2.size()});
		}
	}
	Q1.push_back({1, 1});
	sort(Q2.begin(), Q2.end());
	vector<ll> ans(Q2.size());
	for (int i = 0, j = 0; j < Q2.size(); ++i) {
		while (j < Q2.size()) {
			auto &[a, b, c, d] = Q2[j];
			if (a == i) {
				ans[d] = ft.rsq(b, c);
				++j;
			} else {
				break;
			}
		}
		auto &[a, b] = Q1[i];
		ft.update(a, b - A[a]);
		A[a] = b;
	}
	for (ll x : ans) {
		cout << x << "\n";
	}
	return 0;
}
