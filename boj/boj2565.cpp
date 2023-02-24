#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(501);
	for (int i = 0; i < N; ++i) {
		int x{}, y{};
		cin >> x >> y;
		A[x] = y;
	}
	vector<int> dp(501, 1);
	for (int i = 1; i < 501; ++i) {
		for (int j = 1; j < i; ++j) {
			if (A[j] && A[j] < A[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int ans = N - *max_element(dp.begin(), dp.end());
	cout << ans << "\n";
	return 0;
}
