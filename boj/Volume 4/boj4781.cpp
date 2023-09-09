#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	double x{};
	while (cin >> N >> x, N) {
		int M = 100 * x + EPS;
		vector<int> A(N);
		vector<int> B(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i] >> x;
			B[i] = 100 * x + EPS;
		}
		vector<int> dp(M + 1, -INF);
		dp[0] = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = B[i]; j <= M; ++j) {
				dp[j] = max(dp[j], dp[j - B[i]] + A[i]);
			}
		}
		int ans = *max_element(dp.begin(), dp.end());
		cout << ans << "\n";
	}
	return 0;
}
