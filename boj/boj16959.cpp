#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;
const int dx[16]{-1, -2, -2, -1, 1, 2, 2, 1, -1, -1, 1, 1, -1, 1, 0, 0};
const int dy[16]{-2, -1, 1, 2, 2, 1, -1, -2, -1, 1, -1, 1, 0, 0, -1, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	vector<ii> B(N * N + 1);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			B[A[i][j]] = {i, j};
		}
	}
	vector<vector<int>> D(3 * N * N, vector<int>(3 * N * N, INF));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < 3; ++k) {
				for (int l = 0; l < 3; ++l) {
					D[k * N * N + i * N + j][l * N * N + i * N + j] = k != l;
				}
			}
			for (int k = 0; k < 8; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < N && 0 <= ny && ny < N) {
					D[i * N + j][nx * N + ny] = 1;
				}
			}
			for (int k = 8; k < 16; ++k) {
				int z = k < 12 ? 1 : 2;
				int nx = i + dx[k];
				int ny = j + dy[k];
				while (0 <= nx && nx < N && 0 <= ny && ny < N) {
					D[z * N * N + i * N + j][z * N * N + nx * N + ny] = 1;
					nx += dx[k];
					ny += dy[k];
				}
			}
		}
	}
	for (int k = 0; k < D.size(); ++k) {
		for (int i = 0; i < D.size(); ++i) {
			for (int j = 0; j < D.size(); ++j) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	vector<vector<int>> C(2, vector<int>(3));
	for (int i = 1; i < N * N; ++i) {
		copy(C[1].begin(), C[1].end(), C[0].begin());
		fill(C[1].begin(), C[1].end(), INF);
		auto &[x, y] = B[i];
		auto &[nx, ny] = B[i + 1];
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				C[1][k] = min(C[1][k], C[0][j] + D[j * N * N + x * N + y][k * N * N + nx * N + ny]);
			}
		}
	}
	int ans = *min_element(C[1].begin(), C[1].end());
	cout << ans << "\n";
	return 0;
}
