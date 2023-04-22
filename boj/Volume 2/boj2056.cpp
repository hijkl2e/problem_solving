#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> dp(N + 1);
	for (int i = 1; i <= N; ++i) {
		int x{}, k{};
		cin >> x >> k;
		while (k--) {
			int y{};
			cin >> y;
			dp[i] = max(dp[i], dp[y]);
		}
		dp[i] += x;
	}
	int ans = *max_element(dp.begin(), dp.end());
	cout << ans << "\n";
	return 0;
}
