#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int A[21][21];
int D[401][401];
int B[401], C[401];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	int sx{}, sy{};
	cin >> sx >> sy;
	--sx, --sy;
	for (int i = 0; i < M; ++i) {
		int x1{}, y1{}, x2{}, y2{};
		cin >> x1 >> y1 >> x2 >> y2;
		--x1, --y1, --x2, --y2;
		B[i] = x1 * N + y1;
		C[i] = x2 * N + y2;
	}
	memset(D, 0x3f, sizeof D);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int z = i * N + j;
			D[z][z] = 0;
			if (A[i][j]) {
				continue;
			}
			for (int k = 0; k < 4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < N && 0 <= ny && ny < N && A[nx][ny] == 0) {
					int nz = nx * N + ny;
					D[z][nz] = 1;
				}
			}
		}
	}
	for (int k = 0; k < N * N; ++k) {
		for (int i = 0; i < N * N; ++i) {
			for (int j = 0; j < N * N; ++j) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	int z = sx * N + sy;
	for (int k = 0; k < M; ++k) {
		int p = -1;
		for (int i = 0; i < M; ++i) {
			if (B[i] == -1) {
				continue;
			} else if (p == -1 || D[z][B[p]] > D[z][B[i]]
					|| (D[z][B[p]] == D[z][B[i]] && B[p] > B[i])) {
				p = i;
			}
		}
		if (p == -1 || D[z][B[p]] + D[B[p]][C[p]] > K) {
			K = -1;
			break;
		}
		K += D[B[p]][C[p]] - D[z][B[p]];
		z = C[p], B[p] = -1;
	}
	cout << K << "\n";
	return 0;
}
