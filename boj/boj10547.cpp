#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(A.begin(), A.end());
	sort(B.begin(), B.end());
	for (int i = 0; i < N; ++i) {
		A[i] = (lower_bound(B.begin(), B.end(), A[i]) - B.begin()) / K;
	}
	vector<int> dp;
	for (int i = 0; i < N; ++i) {
		int j = upper_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
		if (j == dp.size()) {
			dp.push_back(A[i]);
		} else {
			dp[j] = A[i];
		}
	}
	int ans = N - dp.size();
	cout << ans << "\n";
	return 0;
}
