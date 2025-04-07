#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(3);
	for (int i = 0; i < 3; ++i) {
		cin >> A[i];
	}
	int sum = accumulate(A.begin(), A.end(), 0);
	vector<int> B(3);
	for (int i = 0; i < 3; ++i) {
		B[i] = sum - 2 * A[2 - i];
	}
	if (*min_element(B.begin(), B.end()) <= 0) {
		cout << "-1\n";
		return 0;
	}
	cout << "1\n";
	for (int i = 0; i < 3; ++i) {
		cout << B[i] / 2 << "." << (B[i] % 2 ? "5" : "0") << (i == 2 ? "\n" : " ");
	}
	return 0;
}
