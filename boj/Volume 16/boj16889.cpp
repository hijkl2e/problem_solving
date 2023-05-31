#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> dp(61);
	for (int i = 0, j = 1, k = 0; i < 61; ++i) {
		dp[i] = k;
		if (--j == 0) {
			j = ++k + 1;
		}
	}
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		ans ^= dp[A[i]];
	}
	cout << (ans ? "koosaga" : "cubelover") << "\n";
	return 0;
}
