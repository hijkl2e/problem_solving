#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> dp(30001, -1);
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j + A[i] < dp.size(); ++j) {
			if (dp[j] == -1) {
				continue;
			}
			int &val = dp[j + A[i]];
			val = dp[j] == -2 || val != -1 ? -2 : (i + 1);
		}
	}
	int M{};
	cin >> M;
	while (M--) {
		int x{};
		cin >> x;
		if (dp[x] < 0) {
			cout << (dp[x] == -1 ? "Impossible" : "Ambiguous") << "\n";
			continue;
		}
		vector<int> B;
		while (x) {
			B.push_back(dp[x]);
			x -= A[dp[x] - 1];
		}
		reverse(B.begin(), B.end());
		for (int i = 0; i < B.size(); ++i) {
			cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
		}
	}
	return 0;
}
