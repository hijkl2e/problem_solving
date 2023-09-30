#include <bits/stdc++.h>

using namespace std;

int solve(int x) {
	int ret{};
	while (x) {
		if (x % 10 == 9) {
			++ret;
		}
		x /= 10;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			A[i][j] = solve(A[i][j]);
			ans += A[i][j];
		}
	}
	int maxv{};
	for (int i = 0; i < N; ++i) {
		maxv = max(maxv, accumulate(A[i].begin(), A[i].end(), 0));
	}
	for (int j = 0; j < M; ++j) {
		int sum{};
		for (int i = 0; i < N; ++i) {
			sum += A[i][j];
		}
		maxv = max(maxv, sum);
	}
	ans -= maxv;
	cout << ans << "\n";
	return 0;
}
