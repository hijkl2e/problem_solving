#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int P{}, N{};
		cin >> P >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		vector<int> dp(20001, INF);
		dp[0] = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = dp.size() - 1; j >= A[i]; --j) {
				dp[j] = min(dp[j], dp[j - A[i]] + 1);
			}
		}
		while (dp[P] == INF) {
			++P;
		}
		cout << P << " " << dp[P] << "\n";
	}
	return 0;
}
