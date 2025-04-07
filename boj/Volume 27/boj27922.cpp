#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<vector<int>> A(N, vector<int>(3));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> A[i][j];
		}
	}
	int ans{};
	for (int j = 0; j < 3; ++j) {
		int k = (j + 1) % 3;
		vector<int> B(N);
		for (int i = 0; i < N; ++i) {
			B[i] = A[i][j] + A[i][k];
		}
		sort(B.rbegin(), B.rend());
		ans = max(ans, accumulate(B.begin(), B.begin() + K, 0));
	}
	cout << ans << "\n";
	return 0;
}
