#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(8);
	for (int i = 0; i < 8; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.begin() + 6);
	do {
		if (A[0] > A[1] && A[1] > A[2] && A[3] > A[4] && A[4] > A[5]
				&& A[0] + A[1] + A[2] == A[6] && A[3] + A[4] + A[5] == A[7]) {
			break;
		}
	} while (next_permutation(A.begin(), A.begin() + 6));
	for (int i = 0; i < 6; ++i) {
		cout << A[i] << (i == 5 ? "\n" : " ");
	}
	return 0;
}
