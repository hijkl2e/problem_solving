#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	vector<int> C(N + 1);
	for (int i = 0; i < N; ++i) {
		C[A[i]] = i;
	}
	for (int i = 0; i < N; ++i) {
		A[i] = C[B[i]] + 1;
	}
	vector<int> dp;
	for (int i = 0; i < N; ++i) {
		int j = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
		if (j == dp.size()) {
			dp.push_back(A[i]);
		} else {
			dp[j] = A[i];
		}
	}
	cout << dp.size() << "\n";
	return 0;
}
