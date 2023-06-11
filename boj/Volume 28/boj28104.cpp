#include <bits/stdc++.h>

using namespace std;

const int dx[4]{0, 0, 1, -1};
const int dy[4]{1, -1, 0, 0};
const vector<int> dz[2][2]{
	{{1, 3}, {0, 2}}, {{0, 3}, {1, 2}}
};

int B[501][501][2];
int C[501][501][2];
bool D[501][501][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, Q{};
	cin >> N >> M >> Q;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	memset(B, -1, sizeof B);
	memset(C, -1, sizeof C);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			for (int k = 0; k < 2; ++k) {
				int cnt{};
				for (int d : dz[A[i][j] == 'N'][k]) {
					int nx = i + dx[d];
					int ny = j + dy[d];
					if (0 <= nx && nx < N && 0 <= ny && ny < M) {
						++cnt;
					}
				}
				D[i][j][k] = cnt == 2;
			}
		}
	}
	vector<int> E;
	for (int l = 0; l < 2; ++l) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				for (int k = 0; k < 2; ++k) {
					if (B[i][j][k] != -1 || (l == 0 && D[i][j][k])) {
						continue;
					}
					int x = i, y = j, z = k;
					int p{};
					while (B[x][y][z] == -1) {
						B[x][y][z] = E.size();
						C[x][y][z] = p++;
						for (int d : dz[A[x][y] == 'N'][z]) {
							int nx = x + dx[d];
							int ny = y + dy[d];
							if (0 <= nx && nx < N && 0 <= ny && ny < M) {
								int nz = z ^ (A[x][y] == A[nx][ny] || d > 1);
								if (B[nx][ny][nz] == -1) {
									x = nx, y = ny, z = nz;
									break;
								}
							}
						}
					}
					E.push_back(l * p);
				}
			}
		}
	}
	while (Q--) {
		int x1{}, y1{}, t1{}, x2{}, y2{}, t2{};
		cin >> x1 >> y1 >> t1 >> x2 >> y2 >> t2;
		--x1, --y1, --x2, --y2;
		if (B[x1][y1][t1] != B[x2][y2][t2]) {
			cout << "-1\n";
			continue;
		}
		int ans = abs(C[x1][y1][t1] - C[x2][y2][t2]);
		int sz = E[B[x1][y1][t1]];
		if (sz) {
			ans = min(ans, sz - ans);
		}
		cout << ans << "\n";
	}
	return 0;
}
