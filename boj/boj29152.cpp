#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	A[N - 1][N - 1] = '1';
	vector<int> L(N);
	vector<int> R(N);
	for (int i = 0; i < N; ++i) {
		L[i] = find(A[i].begin(), A[i].end(), '1') - A[i].begin();
		R[i] = find(A[i].rbegin(), A[i].rend(), '1').base() - A[i].begin() - 1;
	}
	vector<int> dp(4);
	dp[1] = INF;
	int l{}, r{};
	for (int i = 0; i < N; ++i) {
		if (L[i] == N) {
			++dp[0], ++dp[1];
			continue;
		}
		dp[2] = min(R[i] <= l ? dp[0] + l : INF, dp[1] + (R[i] <= r ? r : (2 * R[i] - r))) - L[i] + 1;
		dp[3] = min(r <= L[i] ? dp[1] - r : INF, dp[0] - (l <= L[i] ? l : (2 * L[i] - l))) + R[i] + 1;
		if (i > 0 && L[i - 1] == N) {
			dp[2] = min(dp[2], min(dp[0] + abs(R[i] - l), dp[1] + abs(r - R[i])) + R[i] - L[i] + 1);
			dp[3] = min(dp[3], min(dp[0] + abs(L[i] - l), dp[1] + abs(r - L[i])) + R[i] - L[i] + 1);
		}
		dp[0] = dp[2], dp[1] = dp[3];
		l = L[i], r = R[i];
	}
	cout << (dp[1] < INF ? dp[1] : -1) << "\n";
	return 0;
}
