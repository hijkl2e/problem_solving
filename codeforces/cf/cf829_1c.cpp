#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

ll pow(ll x, ll y) {
	ll ret = 1;
	while (y) {
		if (y % 2) {
			ret = ret * x % MOD;
		}
		x = x * x % MOD;
		y /= 2;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll N{};
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		int cnt = accumulate(A.begin(), A.end(), 0);
		cnt -= accumulate(A.end() - cnt, A.end(), 0);
		ll ans{};
		for (ll i = 1; i <= cnt; ++i) {
			ans += pow(i * i, MOD - 2);
			ans %= MOD;
		}
		ans *= N * (N - 1) / 2 % MOD;
		ans %= MOD;
		cout << ans << "\n";
	}
	return 0;
}
