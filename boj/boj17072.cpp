#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> R(N, vector<int>(M));
	vector<vector<int>> G(N, vector<int>(M));
	vector<vector<int>> B(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> R[i][j] >> G[i][j] >> B[i][j];
		}
	}
	vector<string> A(N, string(M, '.'));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int x = 2126 * R[i][j] + 7152 * G[i][j] + 722 * B[i][j];
			if (x < 510000) {
				A[i][j] = '#';
			} else if (x < 1020000) {
				A[i][j] = 'o';
			} else if (x < 1530000) {
				A[i][j] = '+';
			} else if (x < 2040000) {
				A[i][j] = '-';
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << A[i] << "\n";
	}
	return 0;
}
