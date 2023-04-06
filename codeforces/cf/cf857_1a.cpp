#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> A(200, vector<int>(200));
	for (int i = 0; i < 200; ++i) {
		for (int j = 0; j < 200; ++j) {
			A[i][j] = 256 * i + j;
		}
	}
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		cout << N * M << "\n";
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cout << A[i][j] << (j == M - 1 ? "\n" : " ");
			}
		}
	}
	return 0;
}
