#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{};
	cin >> R >> C;
	vector<vector<int>> A(R, vector<int>(C));
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> A[i][j];
		}
	}
	int X{};
	cin >> X;
	vector<int> B(9);
	int ans{};
	for (int i = 0; i + 2 < R; ++i) {
		for (int j = 0; j + 2 < C; ++j) {
			for (int k = 0; k < 3; ++k) {
				for (int l = 0; l < 3; ++l) {
					B[3 * k + l] = A[i + k][j + l];
				}
			}
			sort(B.begin(), B.end());
			if (B[4] >= X) {
				++ans;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
