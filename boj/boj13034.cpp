#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> dp(N + 1);
	deque<bool> A(10);
	for (int i = 2; i <= N; ++i) {
		fill(A.begin(), A.end(), false);
		for (int j = 0; i - j - 2 >= 0; ++j) {
			A[dp[j] ^ dp[i - j - 2]] = true;
		}
		for (int j = 0; A[j]; ++j) {
			dp[i] = j + 1;
		}
	}
	cout << (dp[N] ? 1 : 2) << "\n";
	return 0;
}
