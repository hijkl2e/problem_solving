#include <bits/stdc++.h>

using namespace std;

int N, ans;
vector<vector<int>> A;
vector<deque<bool>> B;

void solve(int n, int x, int y, int z) {
	if (n == 3) {
		ans = min(ans, z);
		return;
	}
	for (int i = x; i < N - 1; ++i) {
		for (int j = i == x ? y : 1; j < N - 1; ++j) {
			if (B[i][j] || B[i - 1][j] || B[i + 1][j] || B[i][j - 1] || B[i][j + 1]) {
				continue;
			}
			B[i][j] = B[i - 1][j] = B[i + 1][j] = B[i][j - 1] = B[i][j + 1] = true;
			solve(n + 1, i, j + 1, z + A[i][j] + A[i - 1][j] + A[i + 1][j] + A[i][j - 1] + A[i][j + 1]);
			B[i][j] = B[i - 1][j] = B[i + 1][j] = B[i][j - 1] = B[i][j + 1] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.assign(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	B.assign(N, deque<bool>(N));
	ans = 1e9;
	solve(0, 1, 1, 0);
	cout << ans << "\n";
	return 0;
}
