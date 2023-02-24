#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> A(12, vector<int>(12));
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 12; ++j) {
			cin >> A[i][j];
		}
	}
	vector<int> D(12);
	D[0] = A[1][0];
	D[1] = A[0][1];
	for (int i = 2; i < 12; ++i) {
		D[i] = min(D[i - 2] + A[i - 2][i ^ 1], D[(i - 2) ^ 1] + A[(i - 2) ^ 1][i ^ 1]) + A[i ^ 1][i];
	}
	int ans = min(D[10], D[11]);
	cout << ans << "\n";
	return 0;
}
