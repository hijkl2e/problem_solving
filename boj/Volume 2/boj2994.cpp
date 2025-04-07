#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{}, N{};
	cin >> T >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<deque<bool>> dp(N + 1, deque<bool>(T + 1));
	dp[0][0] = true;
	for (int i = 0; i < N; ++i) {
		copy(dp[i].begin(), dp[i].end(), dp[i + 1].begin());
		for (int j = T; j >= A[i]; --j) {
			if (dp[i][j - A[i]]) {
				dp[i + 1][j] = true;
			}
		}
	}
	int p = T;
	while (!dp[N][p]) {
		--p;
	}
	deque<bool> B(N);
	for (int i = N - 1; i >= 0; --i) {
		if (dp[i][p]) {
			continue;
		}
		B[i] = true;
		p -= A[i];
	}
	vector<int> C(N);
	int t1{}, t2{};
	for (int i = 0; i < N; ++i) {
		if (B[i]) {
			C[i] = t1;
			t1 += A[i];
		} else {
			C[i] = t2;
			t2 += A[i];
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << C[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
