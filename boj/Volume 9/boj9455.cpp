#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		vector<vector<int>> A(N, vector<int>(M));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> A[i][j];
			}
		}
		int ans{};
		for (int j = 0; j < M; ++j) {
			for (int i = N - 1, k = N - 1; i >= 0; --i) {
				if (A[i][j]) {
					ans += k-- - i;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
