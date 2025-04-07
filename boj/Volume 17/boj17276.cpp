#include <bits/stdc++.h>

using namespace std;

const int dx[8]{-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8]{0, -1, -1, -1, 0, 1, 1, 1};

int N;
vector<vector<int>> A;

void rotate(int d) {
	vector<vector<int>> B(8, vector<int>(N / 2));
	for (int i = 0; i < 8; ++i) {
		int x = N / 2, y = N / 2;
		for (int j = 0; j < N / 2; ++j) {
			x += dx[i];
			y += dy[i];
			B[i][j] = A[x][y];
		}
	}
	rotate(B.begin(), B.begin() + d / 45, B.end());
	for (int i = 0; i < 8; ++i) {
		int x = N / 2, y = N / 2;
		for (int j = 0; j < N / 2; ++j) {
			x += dx[i];
			y += dy[i];
			A[x][y] = B[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int d{};
		cin >> N >> d;
		d = (d + 360) % 360;
		A.assign(N, vector<int>(N));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> A[i][j];
			}
		}
		rotate(d);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cout << A[i][j] << (j == N - 1 ? "\n" : " ");
			}
		}
	}
	return 0;
}
