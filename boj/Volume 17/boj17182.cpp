#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<vector<int>> D(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> D[i][j];
		}
	}
	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		A[i] = i;
	}
	swap(A[0], A[K]);
	sort(A.begin() + 1, A.end());
	int ans = 1e9;
	do {
		int sum{};
		for (int i = 0; i < N - 1; ++i) {
			sum += D[A[i]][A[i + 1]];
		}
		ans = min(ans, sum);
	} while (next_permutation(A.begin() + 1, A.end()));
	cout << ans << "\n";
	return 0;
}
