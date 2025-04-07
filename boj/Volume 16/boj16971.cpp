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
			B[i] += (j == 0 || j == M - 1 ? 1 : 2) * A[i][j];
			C[j] += (i == 0 || i == N - 1 ? 1 : 2) * A[i][j];
		}
	}
	int sum{};
	for (int i = 0; i < N; ++i) {
		sum += (i == 0 || i == N - 1 ? 1 : 2) * B[i];
	}
	int ans = sum;
	B[0] = max(B[0], B[N - 1]);
	C[0] = max(C[0], C[M - 1]);
	for (int i = 1; i < N - 1; ++i) {
		ans = max(ans, sum + B[0] - B[i]);
	}
	for (int i = 1; i < M - 1; ++i) {
		ans = max(ans, sum + C[0] - C[i]);
	}
	cout << ans << "\n";
	return 0;
}
