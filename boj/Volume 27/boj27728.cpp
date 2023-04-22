#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<int>> B(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		partial_sum(A[i].rbegin(), A[i].rend(), B[i].rbegin());
	}
	vector<vector<int>> C(N, vector<int>(N));
	C[0] = B[0];
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			C[i][j] = min(C[i - 1][j], B[i][j]);
		}
	}
	while (Q--) {
		int sx{}, sy{}, L{};
		cin >> sx >> sy >> L;
		--sx, --sy;
		int ans = B[sx][sy];
		int sum{};
		for (int i = sy; i < N; ++i) {
			ans = min(ans, C[sx - L][i] + sum);
			sum += A[sx][i];
		}
		cout << ans << "\n";
	}
	return 0;
}
