#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	partial_sum(A.begin(), A.end(), A.begin());
	int K{};
	cin >> K;
	if (K > 1132500) {
		cout << K << "\n";
		return 0;
	}
	vector<bitset<1132501>> dp(N + 2);
	dp[0][0] = true;
	for (int i = 0; i <= N; ++i) {
		dp[i + 1] |= dp[i];
		int sum{};
		for (int j = i + 1; j <= N; ++j) {
			sum += A[j] - A[i];
			dp[j + 1] |= dp[i] << sum;
		}
	}
	while (dp[N + 1][K]) {
		++K;
	}
	cout << K << "\n";
	return 0;
}
