#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> A;

int solve(int n, int v) {
	if (n >= 2 * N - 1) {
		return __builtin_popcount(v);
	}
	int ret = solve(n + 2, v);
	for (int i = 0; i < 2 * N - 1; ++i) {
		if (A[n][i] && (v & (1 << i)) == 0) {
			ret = max(ret, solve(n + 2, v | (1 << i)));
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.assign(2 * N - 1, vector<int>(2 * N - 1));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i + j][i - j + N - 1];
		}
	}
	int ans = solve(0, 0) + solve(1, 0);
	cout << ans << "\n";
	return 0;
}
