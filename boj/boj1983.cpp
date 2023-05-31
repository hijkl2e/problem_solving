#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A, B;
	for (int i = 0; i < 2; ++i) {
		auto &v = i ? B : A;
		for (int j = 0; j < N; ++j) {
			int x{};
			cin >> x;
			if (x) {
				v.push_back(x);
			}
		}
	}
	N = min<int>(N, A.size() + B.size());
	vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, -INF));
	dp[0][0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = min<int>(i, A.size()); j >= max<int>(i - N + A.size(), 0); --j) {
			for (int k = min<int>(i, B.size()); k >= max<int>(i - N + B.size(), 0); --k) {
				if (j < A.size() && k < B.size()) {
					dp[j + 1][k + 1] = max(dp[j + 1][k + 1], dp[j][k] + A[j] * B[k]);
				}
				if (j < A.size()) {
					dp[j + 1][k] = max(dp[j + 1][k], dp[j][k]);
				}
				if (k < B.size()) {
					dp[j][k + 1] = max(dp[j][k + 1], dp[j][k]);
				}
			}
		}
	}
	cout << dp.back().back() << "\n";
	return 0;
}
