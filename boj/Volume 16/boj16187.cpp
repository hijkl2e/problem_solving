#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> dp(5001);
	deque<bool> A(10);
	for (int i = 2; i < dp.size(); ++i) {
		fill(A.begin(), A.end(), false);
		for (int j = 0; i - j - 2 >= 0; ++j) {
			A[dp[j] ^ dp[i - j - 2]] = true;
		}
		for (int j = 0; A[j]; ++j) {
			dp[i] = j + 1;
		}
	}
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cout << (dp[N] ? "First" : "Second") << "\n";
	}
	return 0;
}
