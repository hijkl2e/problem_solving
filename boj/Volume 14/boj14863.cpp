#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<ii> A(N);
	vector<ii> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
		cin >> B[i].first >> B[i].second;
		if (A[i] > B[i]) {
			swap(A[i], B[i]);
		}
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		K -= A[i].first;
		ans += A[i].second;
	}
	vector<int> dp(K + 1, -INF);
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		int x = B[i].first - A[i].first;
		int y = B[i].second - A[i].second;
		for (int j = K; j >= x; --j) {
			dp[j] = max(dp[j], dp[j - x] + y);
		}
	}
	ans += *max_element(dp.begin(), dp.end());
	cout << ans << "\n";
	return 0;
}
