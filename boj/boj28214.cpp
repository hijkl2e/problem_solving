#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{}, P{};
	cin >> N >> K >> P;
	vector<vector<int>> A(N, vector<int>(K));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < K; ++j) {
			cin >> A[i][j];
		}
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		if (count(A[i].begin(), A[i].end(), 0) < P) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
