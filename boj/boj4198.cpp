#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = N - 1; i >= 0; --i) {
		cin >> A[i];
	}
	vector<int> dp1(N, 1);
	vector<int> dp2(N, 1);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (A[j] < A[i]) {
				dp1[i] = max(dp1[i], dp1[j] + 1);
			} else {
				dp2[i] = max(dp2[i], dp2[j] + 1);
			}
		}
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		ans = max(ans, dp1[i] + dp2[i] - 1);
	}
	cout << ans << "\n";
	return 0;
}
