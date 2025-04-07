#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> dp;
	for (int i = 0; i < N; ++i) {
		int j = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
		if (j == dp.size()) {
			dp.push_back(A[i]);
		} else {
			dp[j] = A[i];
		}
	}
	int ans = N - dp.size();
	cout << ans << "\n";
	return 0;
}
