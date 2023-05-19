#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (A[i][j] == 0) {
				continue;
			}
			for (int k = j + 1; k < N; ++k) {
				if (A[i][k] && A[j][k]) {
					++ans;
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
