#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> A(9, vector<int>(9));
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> A[i][j];
		}
	}
	int maxv{};
	for (int i = 0; i < 9; ++i) {
		maxv = max(maxv, *max_element(A[i].begin(), A[i].end()));
	}
	cout << maxv << "\n";
	for (int i = 0; i < 9; ++i) {
		auto it = max_element(A[i].begin(), A[i].end());
		if (*it == maxv) {
			cout << i + 1 << " " << it - A[i].begin() + 1 << "\n";
			break;
		}
	}
	return 0;
}
