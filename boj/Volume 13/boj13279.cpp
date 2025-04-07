#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 100003;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<ll> dp(N + 1);
	dp[0] = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = N; j > 0; --j) {
			dp[j] = (dp[j] + dp[j - 1] * A[i]) % MOD;
		}
	}
	int Q{};
	cin >> Q;
	while (Q--) {
		int x{};
		cin >> x;
		cout << dp[x] << "\n";
	}
	return 0;
}
