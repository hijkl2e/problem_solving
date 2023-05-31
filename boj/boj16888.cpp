#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	deque<bool> dp(1000001);
	for (int i = 1; i < dp.size(); ++i) {
		for (int j = 1; j * j <= i; ++j) {
			if (!dp[i - j * j]) {
				dp[i] = true;
				break;
			}
		}
	}
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cout << (dp[N] ? "koosaga" : "cubelover") << "\n";
	}
	return 0;
}
