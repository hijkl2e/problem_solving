#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
		if (A[i].first > A[i].second) {
			swap(A[i].first, A[i].second);
		}
	}
	sort(A.begin(), A.end());
	vector<int> dp(N, 1);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (A[j].first <= A[i].first && A[j].second <= A[i].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int ans = *max_element(dp.begin(), dp.end());
	cout << ans << "\n";
	return 0;
}
