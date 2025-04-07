#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	bitset<16000001> dp;
	dp[0] = true;
	for (int i = 0; i < N; ++i) {
		int sum{};
		for (int j = 0; j < N; ++j) {
			sum += A[i][j] + A[j][i];
		}
		dp |= dp << sum;
	}
	int sum{};
	for (int i = 0; i < N; ++i) {
		sum += accumulate(A[i].begin(), A[i].end(), 0);
	}
	int ans{};
	for (int i = 0; i <= sum; ++i) {
		if (dp[sum - i]) {
			ans = i;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
