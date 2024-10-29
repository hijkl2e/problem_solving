#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

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
	for (int i = 1; i <= N; ++i) {
		partial_sum(A[i].begin(), A[i].end(), A[i].begin());
	}
	vector<int> B(N + 1);
	int ans = -INF;
	for (int i = 1; i <= M; ++i) {
		for (int j = i; j <= M; ++j) {
			for (int k = 1; k <= N; ++k) {
				B[k] = A[k][j] - A[k][i - 1];
			}
			partial_sum(B.begin(), B.end(), B.begin());
			int minv{};
			for (int k = 1; k <= N; ++k) {
				ans = max(ans, B[k] - minv);
				minv = min(minv, B[k]);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
