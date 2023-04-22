#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> dp(N, INF);
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j <= A[i] && i + j < N; ++j) {
			dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}
	cout << (dp[N - 1] == INF ? -1 : dp[N - 1]) << "\n";
	return 0;
}
