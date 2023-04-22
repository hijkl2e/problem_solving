#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	ll ans{};
	for (int k = 0; k < 2; ++k) {
		ll x = 1;
		for (int i = 0; i < N; ++i) {
			ans = (ans + (k ? -1 : 1) * x * A[i]) % MOD;
			x = 2 * x % MOD;
		}
		reverse(A.begin(), A.end());
	}
	ans = (ans + MOD) % MOD;
	cout << ans << "\n";
	return 0;
}
