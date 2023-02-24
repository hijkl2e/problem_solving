#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

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
			res = (res + ft[j]) % MOD;
			j -= LSOne(j);
		}
		return res;
	}
	void update(int i, T v) {
		while (i < ft.size()) {
			ft[i] = (ft[i] + v) % MOD;
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
	vector<ll> B(A.begin(), A.end());
	sort(B.begin(), B.end());
	B.resize(unique(B.begin(), B.end()) - B.begin());
	FT<ll> ft1(B.size()), ft2(B.size());
	ll ans{};
	for (int i = N; i > 0; --i) {
		int x = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
		ll y = (ft1.rsq(x, B.size()) + ft2.rsq(x - 1) * A[i]) % MOD;
		ans = (ans + i * y) % MOD;
		ft1.update(x, (N - i + 1) * A[i] % MOD);
		ft2.update(x, N - i + 1);
	}
	cout << ans << "\n";
	return 0;
}
