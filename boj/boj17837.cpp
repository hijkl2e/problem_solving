#include <bits/stdc++.h>

using namespace std;

const int dx[4]{0, 0, -1, 1};
const int dy[4]{1, -1, 0, 0};

int A[12][12];
vector<int> B[12][12];
int R[10], C[10], D[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < K; ++i) {
		cin >> R[i] >> C[i] >> D[i];
		--R[i], --C[i], --D[i];
		B[R[i]][C[i]].push_back(i);
	}
	int ans = -1;
	for (int t = 1; t < 1001; ++t) {
		for (int i = 0; i < K; ++i) {
			int r = R[i], c = C[i], &d = D[i];
			auto it = find(B[r][c].begin(), B[r][c].end(), i);
			int nx = r + dx[d];
			int ny = c + dy[d];
			if (nx == -1 || nx == N || ny == -1 || ny == N || A[nx][ny] == 2) {
				d ^= 1;
				nx = r + dx[d];
				ny = c + dy[d];
			}
			if (nx == -1 || nx == N || ny == -1 || ny == N || A[nx][ny] == 2) {
				continue;
			}
			for (int j = it - B[r][c].begin(); j < B[r][c].size(); ++j) {
				int z = B[r][c][j];
				R[z] = nx, C[z] = ny;
			}
			if (A[nx][ny]) {
				reverse(it, B[r][c].end());
			}
			copy(it, B[r][c].end(), back_inserter(B[nx][ny]));
			if (B[nx][ny].size() > 3) {
				ans = t;
				t = 1001;
				break;
			}
			B[r][c].erase(it, B[r][c].end());
		}
	}
	cout << ans << "\n";
	return 0;
}
