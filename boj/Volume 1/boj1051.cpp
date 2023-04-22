#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			for (int k = 0; i + k < N && j + k < M; ++k) {
				if (A[i][j] == A[i][j + k] && A[i][j] == A[i + k][j] && A[i][j] == A[i + k][j + k]) {
					ans = max(ans, (k + 1) * (k + 1));
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
