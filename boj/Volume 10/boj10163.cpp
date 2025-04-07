#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> A(1001, vector<int>(1001));
	int N{};
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		int x{}, y{}, w{}, h{};
		cin >> x >> y >> w >> h;
		for (int j = 0; j < w; ++j) {
			for (int k = 0; k < h; ++k) {
				A[x + j][y + k] = i;
			}
		}
	}
	vector<int> B(N + 1);
	for (int i = 0; i < 1001; ++i) {
		for (int j = 0; j < 1001; ++j) {
			++B[A[i][j]];
		}
	}
	for (int i = 1; i <= N; ++i) {
		cout << B[i] << "\n";
	}
	return 0;
}
