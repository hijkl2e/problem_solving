#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	--N;
	vector<int> dp(28);
	dp[0] = 3;
	for (int i = 1; i < dp.size(); ++i) {
		dp[i] = 2 * dp[i - 1] + i + 3;
	}
	char c{};
	for (int i = 27; i >= 0; --i) {
		if (i == 0) {
			c = N ? 'o' : 'm';
			break;
		}
		if (N >= dp[i] - dp[i - 1]) {
			N -= dp[i] - dp[i - 1];
		} else if (N >= dp[i - 1]) {
			c = N - dp[i - 1] ? 'o' : 'm';
			break;
		}
	}
	cout << c << "\n";
	return 0;
}
