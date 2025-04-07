#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int B[4], R[4], C[4];

ii solve(int n, int r, int c) {
	int x = ((r - R[B[r % 2 * 2 + c % 2]]) % n + n) % n;
	int y = ((c - C[B[r % 2 * 2 + c % 2]]) % n + n) % n;
	return {x, y};
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			A[i][j] = i * N + j + 1;
		}
	}
	for (int i = 0; i < 4; ++i) {
		B[i] = i;
	}
	while (Q--) {
		string cmd;
		cin >> cmd;
		if (cmd == "RO") {
			++C[B[0]], ++C[B[1]];
			swap(B[0], B[1]);
		} else if (cmd == "RE") {
			++C[B[2]], ++C[B[3]];
			swap(B[2], B[3]);
		} else if (cmd == "CO") {
			++R[B[0]], ++R[B[2]];
			swap(B[0], B[2]);
		} else if (cmd == "CE") {
			++R[B[1]], ++R[B[3]];
			swap(B[1], B[3]);
		} else {
			int r1{}, c1{}, r2{}, c2{};
			cin >> r1 >> c1 >> r2 >> c2;
			--r1, --c1, --r2, --c2;
			auto [x1, y1] = solve(N, r1, c1);
			auto [x2, y2] = solve(N, r2, c2);
			swap(A[x1][y1], A[x2][y2]);
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			auto [x, y] = solve(N, i, j);
			cout << A[x][y] << (j == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
