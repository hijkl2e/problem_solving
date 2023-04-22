#include <bits/stdc++.h>

using namespace std;

const int dx[4]{0, 1, 0, -1};
const int dy[4]{1, 0, -1, 0};

vector<vector<int>> A;

void rotate(int x1, int y1, int x2, int y2, int R) {
	vector<int> B;
	for (int r = x1, c = y1, d = 0; d < 4;) {
		B.push_back(A[r][c]);
		r += dx[d];
		c += dy[d];
		if ((r == x1 || r == x2) && (c == y1 || c == y2)) {
			++d;
		}
	}
	rotate(B.begin(), B.begin() + R % B.size(), B.end());
	for (int r = x1, c = y1, d = 0, i = 0; d < 4; ++i) {
		A[r][c] = B[i];
		r += dx[d];
		c += dy[d];
		if ((r == x1 || r == x2) && (c == y1 || c == y2)) {
			++d;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, R{};
	cin >> N >> M >> R;
	A.assign(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < N / 2 && i < M / 2; ++i) {
		rotate(i, i, N - i - 1, M - i - 1, R);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << A[i][j] << (j == M - 1 ? "\n" : " ");
		}
	}
	return 0;
}
