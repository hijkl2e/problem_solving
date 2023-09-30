#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> A[i][j];
		}
	}
	int K{};
	cin >> K;
	vector<int> B(M + 1);
	for (int j = 1; j <= M; ++j) {
		for (int i = 1; i <= N; ++i) {
			B[j] += A[i][j];
		}
	}
	partial_sum(B.begin(), B.end(), B.begin());
	int ans{};
	for (int i = K; i <= M; ++i) {
		ans = max(ans, B[i] - B[i - K]);
	}
	cout << ans << "\n";
	return 0;
}
