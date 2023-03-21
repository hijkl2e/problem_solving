#include <bits/stdc++.h>

using namespace std;

const int dx[4]{0, 0, -1, 1};
const int dy[4]{1, -1, 0, 0};
const int dz[4][6]{
	{3, 1, 0, 5, 4, 2}, {2, 1, 5, 0, 4, 3},
	{4, 0, 2, 3, 5, 1}, {1, 5, 2, 3, 0, 4}
};

void solve(vector<int> &A, int d) {
	static vector<int> B(6);
	for (int i = 0; i < 6; ++i) {
		B[i] = A[dz[d][i]];
	}
	swap(A, B);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, x{}, y{}, K{};
	cin >> N >> M >> x >> y >> K;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	vector<int> B(6);
	while (K--) {
		int d{};
		cin >> d;
		--d;
		x += dx[d];
		y += dy[d];
		if (x == -1 || x == N || y == -1 || y == M) {
			x -= dx[d];
			y -= dy[d];
			continue;
		}
		solve(B, d);
		if (A[x][y]) {
			B[5] = A[x][y];
			A[x][y] = 0;
		} else {
			A[x][y] = B[5];
		}
		cout << B[0] << "\n";
	}
	return 0;
}
