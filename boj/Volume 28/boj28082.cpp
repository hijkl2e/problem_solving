#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> dp(50001, INF);
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = dp.size() - 1; j >= A[i]; --j) {
			dp[j] = min(dp[j], dp[j - A[i]] + 1);
		}
	}
	vector<int> B;
	for (int i = 1; i < dp.size(); ++i) {
		if (dp[i] <= K) {
			B.push_back(i);
		}
	}
	cout << B.size() << "\n";
	for (int i = 0; i < B.size(); ++i) {
		cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
	}
	return 0;
}
