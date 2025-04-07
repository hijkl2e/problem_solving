#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	double P{};
	cin >> N >> P >> Q;
	int avg = N * P;
	int i1 = max(avg - 1100, 0);
	int i2 = min(avg + 1100, N);
	vector<double> A(i2 - i1 + 1);
	for (int i = 0; i < A.size(); ++i) {
		int j = i1 + i;
		A[i] = exp(lgamma(N + 1) - lgamma(N - j + 1) - lgamma(j + 1) + j * log(P) + (N - j) * log(1 - P));
	}
	vector<vector<double>> dp(A.size(), vector<double>(A.size()));
	for (int i = 0; i < A.size(); ++i) {
		double minv = A[i];
		for (int j = i; j < A.size(); ++j) {
			minv = min(minv, A[j]);
			dp[i][j] = (j - i + 1) * minv;
		}
	}
	for (int k = 1; k < A.size(); ++k) {
		for (int i = 0; i + k < A.size(); ++i) {
			int j = i + k;
			dp[i][j] = max({dp[i][j], dp[i][j - 1], dp[i + 1][j]});
		}
	}
	cout << fixed << setprecision(10);
	while (Q--) {
		int l{}, r{};
		cin >> l >> r;
		if (r < i1 || i2 < l) {
			cout << 0.0 << "\n";
			continue;
		}
		l = max(l, i1);
		r = min(r, i2);
		cout << dp[l - i1][r - i1] << "\n";
	}
	return 0;
}
