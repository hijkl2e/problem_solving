#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int C{}, N{};
	while (cin >> C >> N) {
		vector<int> A(N);
		vector<int> B(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i] >> B[i];
		}
		vector<vector<int>> dp(N + 1, vector<int>(C + 1, -INF));
		dp[0][0] = 0;
		for (int i = 0; i < N; ++i) {
			copy(dp[i].begin(), dp[i].end(), dp[i + 1].begin());
			for (int j = C; j >= B[i]; --j) {
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - B[i]] + A[i]);
			}
		}
		int p = max_element(dp[N].begin(), dp[N].end()) - dp[N].begin();
		vector<int> D;
		for (int i = N - 1; i >= 0; --i) {
			if (dp[i][p] < dp[i + 1][p]) {
				D.push_back(i);
				p -= B[i];
			}
		}
		reverse(D.begin(), D.end());
		cout << D.size() << "\n";
		for (int i = 0; i < D.size(); ++i) {
			cout << D[i] << (i == D.size() - 1 ? "" : " ");
		}
		cout << "\n";
	}
	return 0;
}
