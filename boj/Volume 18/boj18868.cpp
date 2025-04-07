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
		for (int j = i + 1; j < N; ++j) {
			bool yes = true;
			for (int k = 0; k < M; ++k) {
				for (int l = k + 1; l < M; ++l) {
					if (A[i][k] < A[i][l] ? (A[j][k] >= A[j][l]) : A[i][k] > A[i][l]
							? (A[j][k] <= A[j][l]) : (A[j][k] != A[j][l])) {
						yes = false;
					}
				}
			}
			if (yes) {
				++ans;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
