#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{};
	cin >> R >> C;
	cin.ignore();
	vector<string> A(R);
	for (int i = 0; i < R; ++i) {
		getline(cin, A[i]);
	}
	vector<int> B(10);
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (isdigit(A[i][j])) {
				B[A[i][j] - '0'] = j;
				break;
			}
		}
	}
	vector<int> D(10);
	for (int i = 1;; ++i) {
		int maxv = *max_element(B.begin() + 1, B.end());
		if (maxv == -1) {
			break;
		}
		for (int j = 1; j < 10; ++j) {
			if (B[j] == maxv) {
				D[j] = i;
				B[j] = -1;
			}
		}
	}
	for (int i = 1; i < 10; ++i) {
		cout << D[i] << "\n";
	}
	return 0;
}
