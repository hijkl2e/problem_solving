#include <bits/stdc++.h>

using namespace std;

const int dx[4]{-1, 0, 1, 0};
const int dy[4]{0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, X{};
	cin >> N >> X;
	vector<vector<int>> A(N, vector<int>(N));
	int x{}, y{}, r{}, c{};
	x = y = N / 2;
	for (int i = 1, j = 0, k = 0, d = 0; i <= N * N; ++i) {
		A[x][y] = i;
		if (i == X) {
			r = x + 1;
			c = y + 1;
		}
		x += dx[d];
		y += dy[d];
		if (k++ == j / 2) {
			++j, k = 0;
			d = (d + 1) % 4;
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << A[i][j] << (j == N - 1 ? "\n" : " ");
		}
	}
	cout << r << " " << c << "\n";
	return 0;
}
