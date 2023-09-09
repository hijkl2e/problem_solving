#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{}, Q{};
	cin >> R >> C >> Q;
	vector<vector<int>> A(R + 1, vector<int>(C + 1));
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			cin >> A[i][j];
		}
	}
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
		}
	}
	while (Q--) {
		int r1{}, c1{}, r2{}, c2{};
		cin >> r1 >> c1 >> r2 >> c2;
		int ans = A[r2][c2] - A[r1 - 1][c2] - A[r2][c1 - 1] + A[r1 - 1][c1 - 1];
		ans /= (r2 - r1 + 1) * (c2 - c1 + 1);
		cout << ans << "\n";
	}
	return 0;
}
