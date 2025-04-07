#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{}, H{};
	cin >> R >> C >> H;
	cin.ignore();
	vector<vector<string>> A(H, vector<string>(R));
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < R; ++j) {
			getline(cin, A[i][j]);
		}
	}
	vector<vector<string>> B(A.begin(), A.end());
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < R; ++j) {
			for (int k = 0; k < C; ++k) {
				if (B[i][j][k] == '*') {
					continue;
				}
				int cnt{};
				for (int l = -1; l < 2; ++l) {
					for (int m = -1; m < 2; ++m) {
						for (int n = -1; n < 2; ++n) {
							int nx = i + l;
							int ny = j + m;
							int nz = k + n;
							if (0 <= nx && nx < H && 0 <= ny && ny < R && 0 <= nz && nz < C
									&& A[nx][ny][nz] == '*') {
								++cnt;
							}
						}
					}
				}
				B[i][j][k] = (cnt % 10) + '0';
			}
		}
	}
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < R; ++j) {
			cout << B[i][j] << "\n";
		}
	}
	return 0;
}
