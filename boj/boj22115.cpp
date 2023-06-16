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
	vector<int> dp(K + 1, INF);
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = K; j >= A[i]; --j) {
			dp[j] = min(dp[j], dp[j - A[i]] + 1);
		}
	}
	cout << (dp[K] == INF ? -1 : dp[K]) << "\n";
	return 0;
}
