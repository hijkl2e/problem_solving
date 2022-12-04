#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> A(4, vector<int>(4));

void rotate(int cnt) {
	vector<vector<int>> B(4, vector<int>(4));
	while (cnt--) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				B[j][3 - i] = A[i][j];
			}
		}
		A = B;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> A[i][j];
		}
	}
	int d{};
	cin >> d;
	rotate((4 - d) % 4);
	for (int i = 0; i < 4; ++i) {
		vector<int> B;
		for (int j = 0; j < 4; ++j) {
			if (A[i][j]) {
				B.push_back(A[i][j]);
			}
		}
		for (int j = 0; j + 1 < B.size(); ++j) {
			if (B[j] == B[j + 1]) {
				B.erase(B.begin() + j);
				B[j] *= 2;
			}
		}
		for (int j = 0; j < 4; ++j) {
			A[i][j] = j < B.size() ? B[j] : 0;
		}
	}
	rotate(d);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << A[i][j] << (j == 3 ? "\n" : " ");
		}
	}
	return 0;
}
