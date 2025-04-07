#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{};
	cin >> M;
	vector<vector<int>> A(19, vector<int>(M + 1));
	for (int i = 1; i <= M; ++i) {
		cin >> A[0][i];
	}
	for (int i = 1; i < 19; ++i) {
		for (int j = 1; j <= M; ++j) {
			A[i][j] = A[i - 1][A[i - 1][j]];
		}
	}
	int Q{};
	cin >> Q;
	while (Q--) {
		int N{}, x{};
		cin >> N >> x;
		for (int i = 0; i < 19; ++i) {
			if (N & (1 << i)) {
				x = A[i][x];
			}
		}
		cout << x << "\n";
	}
	return 0;
}
