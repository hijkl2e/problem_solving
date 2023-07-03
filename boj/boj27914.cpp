#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{}, Q{};
	cin >> N >> K >> Q;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<ll> dp(N + 1);
	for (int i = 1; i <= N; ++i) {
		dp[i] = A[i] == K ? 0 : (dp[i - 1] + 1);
	}
	partial_sum(dp.begin(), dp.end(), dp.begin());
	while (Q--) {
		int x{};
		cin >> x;
		cout << dp[x] << "\n";
	}
	return 0;
}
