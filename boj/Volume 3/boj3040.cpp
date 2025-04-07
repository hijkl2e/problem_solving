#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(9);
	for (int i = 0; i < 9; ++i) {
		cin >> A[i];
	}
	int sum = accumulate(A.begin(), A.end(), 0);
	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 9; ++j) {
			if (sum - A[i] - A[j] == 100) {
				for (int k = 0; k < 9; ++k) {
					if (k == i || k == j) {
						continue;
					}
					cout << A[k] << "\n";
				}
			}
		}
	}
	return 0;
}
