#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<deque<bool>> A;

bool solve(int sx, int sy, int r, int c, vector<deque<bool>> &B) {
	if (sx + r > N || sy + c > M) {
		return false;
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (B[i][j] && A[sx + i][sy + j]) {
				return false;
			}
		}
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (B[i][j]) {
				A[sx + i][sy + j] = true;
			}
		}
	}
	return true;
}

void rotate(int r, int c, vector<deque<bool>> &B) {
	vector<deque<bool>> C(c, deque<bool>(r));
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			C[j][r - i - 1] = B[i][j];
		}
	}
	B = C;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> K;
	A.assign(N, deque<bool>(M));
	while (K--) {
		int R{}, C{};
		cin >> R >> C;
		vector<deque<bool>> B(R, deque<bool>(C));
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				int x{};
				cin >> x;
				B[i][j] = x;
			}
		}
		for (int k = 0; k < 4; ++k) {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M; ++j) {
					if (solve(i, j, R, C, B)) {
						i = N, k = 4;
						break;
					}
				}
			}
			rotate(R, C, B);
			swap(R, C);
		}
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		ans += accumulate(A[i].begin(), A[i].end(), 0);
	}
	cout << ans << "\n";
	return 0;
}
