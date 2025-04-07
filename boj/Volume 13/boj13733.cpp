#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(6);
	for (int i = 0; i < 6; ++i) {
		cin >> A[i];
	}
	bool yes = A[0] == A[2] && A[2] == A[4] && A[1] + A[3] + A[5] == A[0];
	for (int i = 2; i < 4; ++i) {
		for (int j = 4; j < 6; ++j) {
			yes |= A[i] + A[j] == A[0] && A[i ^ 1] == A[j ^ 1] && A[i ^ 1] + A[1] == A[0];
		}
	}
	cout << (yes ? "YES" : "NO") << "\n";
	return 0;
}
