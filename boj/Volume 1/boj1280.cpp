#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

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
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		++A[i];
	}
	int sz = 2e5 + 3;
	FT ft1(sz);
	FT ft2(sz);
	ft1.update(A[0], 1);
	ft2.update(A[0], A[0]);
	ll ans = 1;
	for (int i = 1; i < N; ++i) {
		ll x = ((2 * ft1.rsq(A[i]) - i) * A[i] + ft2.rsq(sz) - 2 * ft2.rsq(A[i])) % MOD;
		ans = (ans * x) % MOD;
		ft1.update(A[i], 1);
		ft2.update(A[i], A[i]);
	}
	cout << ans << "\n";
	return 0;
}
