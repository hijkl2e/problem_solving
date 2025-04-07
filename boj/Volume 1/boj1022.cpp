#include <bits/stdc++.h>

using namespace std;

string solve(int r, int c) {
	int k = max(abs(r), abs(c));
	int x = (2 * k + 1) * (2 * k + 1);
	if (r == k) {
		x -= k - c;
	} else if (c == -k) {
		x -= 3 * k - r;
	} else if (r == -k) {
		x -= 5 * k + c;
	} else {
		x -= 7 * k + r;
	}
	return to_string(x);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int r1{}, c1{}, r2{}, c2{};
	cin >> r1 >> c1 >> r2 >> c2;
	vector<vector<string>> A(r2 - r1 + 1, vector<string>(c2 - c1 + 1));
	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < A[i].size(); ++j) {
			A[i][j] = solve(r1 + i, c1 + j);
		}
	}
	int len{};
	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < A[i].size(); ++j) {
			len = max<int>(len, A[i][j].size());
		}
	}
	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < A[i].size(); ++j) {
			cout << setw(len) << A[i][j] << (j == A[i].size() - 1 ? "\n" : " ");
		}
	}
	return 0;
}
