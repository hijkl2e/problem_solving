#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, S{};
	cin >> N >> S;
	vector<ii> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A.begin(), A.end());
	vector<int> dp(N + 1);
	for (int i = 1, j = 0; i <= N; ++i) {
		while (A[i].first - A[j + 1].first >= S) {
			++j;
		}
		dp[i] = max(dp[i - 1], dp[j] + A[i].second);
	}
	cout << dp[N] << "\n";
	return 0;
}
