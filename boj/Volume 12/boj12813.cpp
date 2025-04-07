#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string A, B;
	getline(cin, A);
	getline(cin, B);
	vector<string> C(5, string(A.size(), '0'));
	for (int i = 0; i < A.size(); ++i) {
		C[0][i] = A[i] & B[i];
		C[1][i] = A[i] | B[i];
		C[2][i] = (A[i] ^ B[i]) | '0';
		C[3][i] = A[i] ^ 1;
		C[4][i] = B[i] ^ 1;
	}
	for (auto &s : C) {
		cout << s << "\n";
	}
	return 0;
}
