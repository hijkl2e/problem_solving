#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const int INF = 0x3f3f3f3f;
const int dx[6]{1, -1, 0, 0, 0, 0};
const int dy[6]{0, 0, 1, -1, 0, 0};
const int dz[6]{0, 0, 0, 0, 1, -1};

vector<vector<int>> A[5];
int B[5];
int D[5][5][5];
int ans;

void bfs() {
	if (A[B[0]][0][0] == 0) {
		return;
	}
	memset(D, 0x3f, sizeof D);
	queue<iii> q;
	D[0][0][0] = 0;
	q.push({0, 0, 0});
	while (q.size()) {
		auto [x, y, z] = q.front(); q.pop();
		for (int i = 0; i < 6; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && 0 <= nz && nz < 5
					&& A[B[nx]][ny][nz] && D[nx][ny][nz] == INF) {
				D[nx][ny][nz] = D[x][y][z] + 1;
				q.push({nx, ny, nz});
			}
		}
	}
	ans = min(ans, D[4][4][4]);
	if (ans == 12) {
		cout << "12\n";
		exit(0);
	}
}

void solve2() {
	for (int i = 0; i < 5; ++i) {
		B[i] = i;
	}
	do {
		bfs();
	} while (next_permutation(B, B + 5));
}

void rotate(vector<vector<int>> &A) {
	static vector<vector<int>> B(5, vector<int>(5));
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			B[i][j] = A[4 - j][i];
		}
	}
	swap(A, B);
}

void solve1(int n) {
	if (n == 5) {
		return solve2();
	}
	for (int i = 0; i < 4; ++i) {
		solve1(n + 1);
		rotate(A[n]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < 5; ++i) {
		A[i].assign(5, vector<int>(5));
		for (int j = 0; j < 5; ++j) {
			for (int k = 0; k < 5; ++k) {
				cin >> A[i][j][k];
			}
		}
	}
	ans = INF;
	solve1(0);
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
