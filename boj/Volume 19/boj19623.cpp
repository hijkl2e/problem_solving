#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<iii> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		auto &[e, s, p] = A[i];
		cin >> s >> e >> p;
	}
	sort(A.begin() + 1, A.end());
	vector<int> dp(N + 1);
	for (int i = 1; i <= N; ++i) {
		auto &[e, s, p] = A[i];
		int x = upper_bound(A.begin() + 1, A.begin() + i, make_tuple(s, -1, -1)) - A.begin();
		dp[i] = max(dp[x - 1] + p, dp[i - 1]);
	}
	cout << dp[N] << "\n";
	return 0;
}
