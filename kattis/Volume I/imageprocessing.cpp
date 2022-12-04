#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int H{}, W{}, N{}, M{};
	cin >> H >> W >> N >> M;
	vector<vector<int>> A(H, vector<int>(W));
	vector<vector<int>> B(N, vector<int>(M));
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> A[i][j];
		}
	}
	for (int i = N - 1; i >= 0; --i) {
		for (int j = M - 1; j >= 0; --j) {
			cin >> B[i][j];
		}
	}
	for (int i = 0; i < H - N + 1; ++i) {
		for (int j = 0; j < W - M + 1; ++j) {
			int x{};
			for (int k = 0; k < N; ++k) {
				for (int l = 0; l < M; ++l) {
					x += A[i + k][j + l] * B[k][l];
				}
			}
			cout << x << (j == W - M ? "\n" : " ");
		}
	}
	return 0;
}
