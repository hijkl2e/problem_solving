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
	vector<int> B(N);
	vector<int> C(M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			B[i] += A[i][j];
			C[j] += A[i][j];
		}
	}
	int ans = -1e9;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				for (int l = k + 1; l < M; ++l) {
					ans = max(ans, B[i] + B[j] + C[k] + C[l]
							- A[i][k] - A[i][l] - A[j][k] - A[j][l] + (j - i - 1) * (l - k - 1));
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
