#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	int ans{};
	for (int i = 0; i < M; ++i) {
		for (int j = i + 1; j < M; ++j) {
			for (int k = j + 1; k < M; ++k) {
				int sum{};
				for (int l = 0; l < N; ++l) {
					sum += max({A[l][i], A[l][j], A[l][k]});
				}
				ans = max(ans, sum);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
