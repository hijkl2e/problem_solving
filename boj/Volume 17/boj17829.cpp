#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	vector<int> B(4);
	while (N > 1) {
		vector<vector<int>> C(N / 2, vector<int>(N / 2));
		for (int i = 0; i < N; i += 2) {
			for (int j = 0; j < N; j += 2) {
				B[0] = A[i][j];
				B[1] = A[i][j + 1];
				B[2] = A[i + 1][j];
				B[3] = A[i + 1][j + 1];
				sort(B.begin(), B.end());
				C[i / 2][j / 2] = B[2];
			}
		}
		A = C;
		N /= 2;
	}
	cout << A[0][0] << "\n";
	return 0;
}
