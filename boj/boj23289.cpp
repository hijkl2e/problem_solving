#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

vector<vector<int>> rotate(vector<vector<int>> &A) {
	vector<vector<int>> ret(A[0].size(), vector<int>(A.size()));
	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < A[i].size(); ++j) {
			ret[j][A.size() - i - 1] = A[i][j];
		}
	}
	return ret;
}

vector<vector<int>> rotate_b(vector<vector<int>> &B) {
	vector<vector<int>> ret(B[0].size(), vector<int>(B.size()));
	for (int i = 0; i < B.size(); ++i) {
		for (int j = 0; j < B[i].size(); ++j) {
			for (int k = 1; k < 3; ++k) {
				if (B[i][j] & k) {
					ret[j + k - 1][B.size() - i - 1] |= k ^ 3;
				}
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{}, K{};
	cin >> R >> C >> K;
	vector<vector<int>> A(R, vector<int>(C));
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> A[i][j];
			if (A[i][j] == 2 || A[i][j] == 3) {
				A[i][j] ^= 1;
			}
		}
	}
	vector<vector<int>> B(R, vector<int>(C));
	int M{};
	cin >> M;
	while (M--) {
		int x{}, y{}, t{};
		cin >> x >> y >> t;
		--x, --y;
		B[x][y] |= 1 << t;
	}
	vector<vector<int>> D(R, vector<int>(C));
	vector<deque<bool>> F(21, deque<bool>(21));
	int ans{};
	while (ans < 101) {
		bool yes = true;
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				if (A[i][j] == 5 && D[i][j] < K) {
					yes = false;
				}
			}
		}
		if (yes) {
			break;
		}
		queue<ii> q;
		for (int k = 1; k < 5; ++k) {
			for (int i = 0; i < R; ++i) {
				for (int j = 0; j < C; ++j) {
					if (A[i][j] != k) {
						continue;
					}
					F[i][j + 1] = true;
					q.push({i, j + 1});
					while (q.size()) {
						auto [x, y] = q.front(); q.pop();
						F[x][y] = false;
						D[x][y] += 6 - y + j;
						if (y - j == 5 || y == C - 1) {
							continue;
						}
						if (x > 0 && (B[x][y] & 1) == 0 && (B[x - 1][y] & 2) == 0 && !F[x - 1][y + 1]) {
							F[x - 1][y + 1] = true;
							q.push({x - 1, y + 1});
						}
						if ((B[x][y] & 2) == 0 && !F[x][y + 1]) {
							F[x][y + 1] = true;
							q.push({x, y + 1});
						}
						if (x + 1 < R && (B[x + 1][y] & 1) == 0 && (B[x + 1][y] & 2) == 0 && !F[x + 1][y + 1]) {
							F[x + 1][y + 1] = true;
							q.push({x + 1, y + 1});
						}
					}
				}
			}
			A = rotate(A);
			B = rotate_b(B);
			D = rotate(D);
			swap(R, C);
		}
		vector<vector<int>> E = D;
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				if (i > 0 && (B[i][j] & 1) == 0) {
					int d = (E[i][j] - E[i - 1][j]) / 4;
					D[i][j] -= d;
					D[i - 1][j] += d;
				}
				if (j + 1 < C && (B[i][j] & 2) == 0) {
					int d = (E[i][j] - E[i][j + 1]) / 4;
					D[i][j] -= d;
					D[i][j + 1] += d;
				}
			}
		}
		for (int i = 0; i < R; ++i) {
			D[i][0] = max(D[i][0] - 1, 0);
			D[i][C - 1] = max(D[i][C - 1] - 1, 0);
		}
		for (int i = 1; i < C - 1; ++i) {
			D[0][i] = max(D[0][i] - 1, 0);
			D[R - 1][i] = max(D[R - 1][i] - 1, 0);
		}
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
