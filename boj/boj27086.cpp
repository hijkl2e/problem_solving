#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, x{}, y{};
	cin >> N >> x >> y;
	vector<int> X(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i];
	}
	vector<int> A(200001);
	for (int i = 0; i < N; ++i) {
		++A[X[i]];
	}
	vector<int> psum(A.size());
	partial_sum(A.begin(), A.end(), psum.begin());
	vector<ll> dp(A.size());
	for (int i = A.size() - 1; i > 0; --i) {
		dp[i] = i + x < A.size() ? dp[i + x] + A[i + x] : 0;
		dp[i] = (dp[i] + N - psum[i]) % MOD;
	}
	ll ans{};
	for (int i = 0; i < N; ++i) {
		ans += dp[X[i]];
	}
	ans = ans % MOD * y % MOD;
	cout << ans << " " << dp[X[0]] * y % MOD << "\n";
	return 0;
}
