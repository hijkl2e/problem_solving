#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, P{};
	cin >> N >> P;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		A[i] -= P;
	}
	vector<int> dp(N);
	for (int i = 0; i < N; ++i) {
		dp[i] = max(i ? dp[i - 1] : 0, 0) + A[i];
	}
	int ans = *max_element(dp.begin(), dp.end());
	cout << ans << "\n";
	return 0;
}
