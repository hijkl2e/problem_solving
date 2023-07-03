#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> dp(N);
	for (int i = N - 1; i >= 0; --i) {
		dp[i] = (i + A[i] + 1 < N ? dp[i + A[i] + 1] : 0) + 1;
	}
	for (int i = 0; i < N; ++i) {
		cout << dp[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
