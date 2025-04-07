#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	vector<int> dp(N + 1);
	dp[N] = 1;
	for (int i = N - 1; i >= 0; --i) {
		dp[i] = dp[i + 1] + (S.substr(i, 8) == "longlong" ? dp[i + 8] : 0);
	}
	cout << dp[0] << "\n";
	return 0;
}
