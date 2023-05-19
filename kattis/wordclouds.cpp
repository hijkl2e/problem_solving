#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, C{};
	cin >> N >> C;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
	}
	vector<int> dp(N + 1, INF);
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		int maxv{}, sum{};
		for (int j = i; j >= 0; --j) {
			sum += A[j];
			if (sum > C) {
				break;
			}
			maxv = max(maxv, B[j]);
			dp[i + 1] = min(dp[i + 1], dp[j] + maxv);
		}
	}
	cout << dp[N] << "\n";
	return 0;
}
