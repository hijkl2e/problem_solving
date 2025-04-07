#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<bitset<50001>> dp(K + 1);
	dp[0][0] = true;
	for (int i = 0; i < N; ++i) {
		for (int j = K; j > 0; --j) {
			dp[j] |= dp[j - 1] << A[i];
		}
	}
	for (int i = 1; i <= K; ++i) {
		dp[0] |= dp[i];
	}
	vector<int> B;
	for (int i = 1; i < 50001; ++i) {
		if (dp[0][i]) {
			B.push_back(i);
		}
	}
	cout << B.size() << "\n";
	for (int i = 0; i < B.size(); ++i) {
		cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
	}
	return 0;
}
