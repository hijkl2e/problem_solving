#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<vector<int>> B;

ll solve(int x1, int y1, int x2, int y2) {
	return B[x2][y2] - B[x1 - 1][y2] - B[x2][y1 - 1] + B[x1 - 1][y1 - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	B.assign(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			B[i][j] = B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1] + A[i - 1][j - 1] - '0';
		}
	}
	ll ans{};
	for (int i = 1; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			ans = max(ans, solve(1, 1, i, M) * solve(i + 1, 1, j, M) * solve(j + 1, 1, N, M));
		}
		for (int j = 1; j < M; ++j) {
			ans = max(ans, solve(1, 1, i, M) * solve(i + 1, 1, N, j) * solve(i + 1, j + 1, N, M));
			ans = max(ans, solve(1, 1, i, j) * solve(1, j + 1, i, M) * solve(i + 1, 1, N, M));
		}
	}
	for (int i = 1; i < M; ++i) {
		for (int j = i + 1; j < M; ++j) {
			ans = max(ans, solve(1, 1, N, i) * solve(1, i + 1, N, j) * solve(1, j + 1, N, M));
		}
		for (int j = 1; j < N; ++j) {
			ans = max(ans, solve(1, 1, N, i) * solve(1, i + 1, j, M) * solve(j + 1, i + 1, N, M));
			ans = max(ans, solve(1, 1, j, i) * solve(j + 1, 1, N, i) * solve(1, i + 1, N, M));
		}
	}
	cout << ans << "\n";
	return 0;
}
