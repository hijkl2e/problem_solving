#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<double> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<double> dp(N);
	for (int i = 0; i < N; ++i) {
		dp[i] = max(i ? dp[i - 1] : 1.0, 1.0) * A[i];
	}
	double ans = *max_element(dp.begin(), dp.end()) + EPS;
	cout << fixed << setprecision(3);
	cout << ans << "\n";
	return 0;
}
