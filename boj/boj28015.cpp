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
	for (int i = 0; i < N; ++i) {
		int cnt{};
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == 0) {
				if (cnt) {
					ans += cnt / 2 + 1;
					cnt = 0;
				}
			} else if (j == 0 || A[i][j] != A[i][j - 1]) {
				++cnt;
			}
		}
		if (cnt) {
			ans += cnt / 2 + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
