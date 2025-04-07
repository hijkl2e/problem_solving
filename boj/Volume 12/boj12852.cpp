#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> dp(N + 1, 1e9);
	vector<int> par(N + 1);
	dp[N] = 0;
	for (int i = N; i > 1; --i) {
		if (i % 3 == 0 && dp[i / 3] > dp[i] + 1) {
			dp[i / 3] = dp[i] + 1;
			par[i / 3] = i;
		}
		if (i % 2 == 0 && dp[i / 2] > dp[i] + 1) {
			dp[i / 2] = dp[i] + 1;
			par[i / 2] = i;
		}
		if (dp[i - 1] > dp[i] + 1) {
			dp[i - 1] = dp[i] + 1;
			par[i - 1] = i;
		}
	}
	stack<int> st;
	int x = 1;
	while (par[x]) {
		st.push(x);
		x = par[x];
	}
	st.push(x);
	cout << dp[1] << "\n";
	while (st.size()) {
		int x = st.top(); st.pop();
		cout << x << (st.empty() ? "\n" : " ");
	}
	return 0;
}
