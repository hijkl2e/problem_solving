#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int> &A) {
	for (int i = 1; i < 25; i += 4) {
		for (int j = 1; j < 4; ++j) {
			if (A[i] != A[i + j]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> A{
		{2, 4, 6, 8, 10, 12, 23, 21},
		{5, 6, 17, 18, 21, 22, 13, 14},
		{3, 4, 17, 19, 10, 9, 16, 14}
	};
	vector<int> B(25);
	for (int i = 1; i < 25; ++i) {
		cin >> B[i];
	}
	bool yes{};
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				int x = B[A[i][0]], y = B[A[i][1]];
				for (int l = 0; l < 6; ++l) {
					B[A[i][l]] = B[A[i][l + 2]];
				}
				B[A[i][6]] = x, B[A[i][7]] = y;
				if (k % 2 == 0 && solve(B)) {
					yes = true;
				}
			}
		}
	}
	cout << yes << "\n";
	return 0;
}
