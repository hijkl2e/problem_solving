#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{}, K{};
	cin >> M >> K;
	vector<int> A;
	for (int i = 1; i <= M; ++i) {
		int j = i;
		int sum{};
		while (j) {
			sum += j % 10;
			j /= 10;
		}
		if (i % sum == 0) {
			A.push_back(i);
		}
	}
	vector<int> dp(M + 1);
	dp[0] = 1;
	for (int x : A) {
		for (int i = 0; i + x <= M; ++i) {
			dp[i + x] = (dp[i + x] + dp[i]) % K;
		}
	}
	cout << dp[M] << "\n";
	return 0;
}
