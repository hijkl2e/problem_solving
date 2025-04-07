#include <bits/stdc++.h>

using namespace std;

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
	vector<vector<int>> B(N, vector<int>(M));
	for (int j = 0; j < M - 1; ++j) {
		for (int i = 0; i < N; ++i) {
			B[i][j] += A[i][j] - '0';
			for (int k = -1; k < 2; ++k) {
				if (0 <= i + k && i + k < N) {
					B[i + k][j + 1] = max(B[i + k][j + 1], B[i][j]);
				}
			}
		}
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		ans = max(ans, B[i][M - 1]);
	}
	cout << ans << "\n";
	return 0;
}
