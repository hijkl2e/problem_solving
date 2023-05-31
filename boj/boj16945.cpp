#include <bits/stdc++.h>

using namespace std;

void rotate1(vector<vector<int>> &A) {
	static vector<vector<int>> B(3, vector<int>(3));
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			B[i][j] = A[2 - j][i];
		}
	}
	swap(A, B);
}

void rotate2(vector<vector<int>> &A) {
	for (int i = 0; i < 3; ++i) {
		reverse(A[i].begin(), A[i].end());
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> A{
		{2, 7, 6}, {9, 5, 1}, {4, 3, 8}
	};
	vector<vector<int>> B(3, vector<int>(3));
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> B[i][j];
		}
	}
	int ans = 1e9;
	for (int k = 0; k < 8; ++k) {
		int cnt{};
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				cnt += abs(A[i][j] - B[i][j]);
			}
		}
		ans = min(ans, cnt);
		if (k % 4 == 3) {
			rotate2(A);
		} else {
			rotate1(A);
		}
	}
	cout << ans << "\n";
	return 0;
}
