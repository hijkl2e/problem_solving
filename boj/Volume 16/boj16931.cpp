#include <bits/stdc++.h>

using namespace std;

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
	int ans = N * M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			ans += max(A[i][j] - (j ? A[i][j - 1] : 0), 0);
		}
	}
	for (int j = 0; j < M; ++j) {
		for (int i = 0; i < N; ++i) {
			ans += max(A[i][j] - (i ? A[i - 1][j] : 0), 0);
		}
	}
	ans *= 2;
	cout << ans << "\n";
	return 0;
}
