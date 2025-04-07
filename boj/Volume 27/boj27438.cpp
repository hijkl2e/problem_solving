#include <bits/stdc++.h>

using namespace std;

vector<int> dp(11);
vector<int> T(8);

string solve(int len, int n, int x) {
	if (x == 3) {
		string ret = len ? to_string(n - 1) : "";
		while (ret.size() < len) {
			ret = "0" + ret;
		}
		return ret;
	}
	for (int i = 0; i < 10; ++i) {
		int sum = dp[len - 1];
		if (i == 6) {
			sum = T[len + x - 3];
			sum += (x < 2 ? 9 : 0) * dp[len + x - 3];
			sum += (x < 1 ? 9 : 0) * dp[len + x - 2];
		}
		if (n <= sum) {
			return to_string(i) + solve(len - 1, n, i == 6 ? x + 1 : 0);
		}
		n -= sum;
	}
	assert(false);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	dp[3] = 1;
	for (int i = 4; i < dp.size(); ++i) {
		dp[i] = 1;
		for (int j = 4; j < i; ++j) {
			dp[i] *= 10;
		}
		dp[i] += dp[i - 1] + dp[i - 2] + dp[i - 3];
		dp[i] *= 9;
	}
	partial_sum(dp.begin(), dp.end(), dp.begin());
	T[0] = 1;
	for (int i = 1; i < T.size(); ++i) {
		T[i] = 10 * T[i - 1];
	}
	string ans = solve(10, N, 0);
	while (ans[0] == '0') {
		ans.erase(ans.begin());
	}
	cout << ans << "\n";
	return 0;
}
