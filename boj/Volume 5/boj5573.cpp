#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<int>> B(N + 1, vector<int>(M + 1));
	B[0][0] = K - 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int x = B[i][j] / 2;
			int y = (B[i][j] + 1) / 2;
			if (A[i][j] % 2) {
				swap(x, y);
			}
			B[i][j + 1] += x;
			B[i + 1][j] += y;
			A[i][j] ^= B[i][j] % 2;
		}
	}
	int x{}, y{};
	while (x < N && y < M) {
		if (A[x][y]) {
			++y;
		} else {
			++x;
		}
	}
	++x, ++y;
	cout << x << " " << y << "\n";
	return 0;
}
