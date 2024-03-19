#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int sum = accumulate(A.begin(), A.end(), 0);
	vector<ll> dp(sum + 1);
	dp[0] = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = sum - A[i]; j >= 0; --j) {
			dp[j + A[i]] |= dp[j] << 1;
		}
	}
	int minv = 1e9;
	for (int i = 0; i <= sum; ++i) {
		if (dp[i] & (1LL << (N / 2))) {
			minv = min(minv, abs(sum - 2 * i));
		}
	}
	cout << (sum - minv) / 2 << " " << (sum + minv) / 2 << "\n";
	return 0;
}
