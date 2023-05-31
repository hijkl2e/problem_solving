#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, y{}, a{}, b{}, N{};
	cin >> x >> y >> a >> b >> N;
	cout << setfill('0') << setw(2);
	if (N < 2) {
		cout << (N ? b : a) << "\n";
		return 0;
	}
	vector<vector<int>> dp(101, vector<int>(101, -1));
	vector<int> A{a, b};
	int ans{};
	for (int i = 2; i <= N; ++i) {
		if (dp[a][b] == -1) {
			dp[a][b] = i;
			int c = (x * b + y * a) % 100;
			A.push_back(c);
			a = b, ans = b = c;
		} else {
			ans = A[(N - dp[a][b]) % (i - dp[a][b]) + dp[a][b]];
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
