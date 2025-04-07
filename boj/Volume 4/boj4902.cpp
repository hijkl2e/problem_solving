#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	for (int tc = 1; cin >> N, N; ++tc) {
		vector<vector<int>> A(N + 1);
		for (int i = 1; i <= N; ++i) {
			A[i].resize(2 * i);
			for (int j = 1; j < 2 * i; ++j) {
				cin >> A[i][j];
			}
		}
		for (int i = 1; i <= N; ++i) {
			partial_sum(A[i].begin(), A[i].end(), A[i].begin());
		}
		int ans = -1e9;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j < 2 * i; j += 2) {
				int sum{};
				for (int k = i; k <= N; ++k) {
					sum += A[k][j + 2 * (k - i)] - A[k][j - 1];
					ans = max(ans, sum);
				}
			}
		}
		for (int i = N; i > 0; --i) {
			for (int j = 2; j < 2 * i; j += 2) {
				int sum{};
				for (int k = i; j < 2 * k && j - 2 * (i - k) > 0; --k) {
					sum += A[k][j] - A[k][j - 2 * (i - k) - 1];
					ans = max(ans, sum);
				}
			}
		}
		cout << tc << ". " << ans << "\n";
	}
	return 0;
}
