#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(5);
	for (int i = 0; i < 5; ++i) {
		cin >> A[i];
	}
	vector<int> B(5);
	for (int i = 0; i < 5; ++i) {
		B[i] = i + 1;
	}
	while (A != B) {
		for (int i = 0; i < 4; ++i) {
			if (A[i] < A[i + 1]) {
				continue;
			}
			swap(A[i], A[i + 1]);
			for (int j = 0; j < 5; ++j) {
				cout << A[j] << (j == 4 ? "\n" : " ");
			}
		}
	}
	return 0;
}
