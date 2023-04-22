#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

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
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].second >> A[i].first;
		A[i].second += 200001;
	}
	sort(A.rbegin(), A.rend());
	vector<ll> B(400004);
	FT ft(400004);
	ll ans{};
	for (int i = 0, j = 1; i < N; i = j++) {
		while (j < N && A[i].first == A[j].first) {
			++j;
		}
		for (int k = i; k < j; ++k) {
			ll cnt = ft.rsq(A[k].second - 1);
			ans += cnt * (i - cnt - B[A[k].second]) % MOD;
		}
		for (int k = i; k < j; ++k) {
			++B[A[k].second];
			ft.update(A[k].second, 1);
		}
	}
	ans %= MOD;
	cout << ans << "\n";
	return 0;
}
