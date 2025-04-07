#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	vector<vector<int>> A(3, vector<int>(N + 1));
	for (int i = 1; i <= N; ++i) {
		int x{};
		cin >> x;
		++A[x - 1][i];
	}
	for (int i = 0; i < 3; ++i) {
		partial_sum(A[i].begin(), A[i].end(), A[i].begin());
	}
	while (Q--) {
		int a{}, b{};
		cin >> a >> b;
		for (int i = 0; i < 3; ++i) {
			int ans = A[i][b] - A[i][a - 1];
			cout << ans << (i == 2 ? "\n" : " ");
		}
	}
	return 0;
}
