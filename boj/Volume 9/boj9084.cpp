#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		int M{};
		cin >> M;
		vector<int> dp(M + 1);
		dp[0] = 1;
		for (int i = 0; i < N; ++i) {
			for (int j = A[i]; j <= M; ++j) {
				dp[j] += dp[j - A[i]];
			}
		}
		cout << dp[M] << "\n";
	}
	return 0;
}
