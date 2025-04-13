#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A, B;
	while (N--) {
		int v{}, c{}, k{};
		cin >> v >> c >> k;
		for (int i = 1; k >= i; i *= 2) {
			A.push_back(i * v);
			B.push_back(i * c);
			k -= i;
		}
		if (k) {
			A.push_back(k * v);
			B.push_back(k * c);
		}
	}
	vector<int> dp(M + 1);
	for (int i = 0; i < A.size(); ++i) {
		for (int j = M; j >= A[i]; --j) {
			dp[j] = max(dp[j], dp[j - A[i]] + B[i]);
		}
	}
	int ans = *max_element(dp.begin(), dp.end());
	cout << ans << "\n";
	return 0;
}
