#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	string A(S.size(), '0');
	string B(S.size(), '0');
	for (int i = 0, j = 0; i < S.size(); i = ++j) {
		while (j < S.size() && S[j] == 'M') {
			++j;
		}
		B[i] = '1';
		if (j < S.size()) {
			A[i] = '5';
			B[j] = '5';
		} else {
			fill(A.begin() + i, A.end(), '1');
		}
	}
	cout << A << "\n";
	cout << B << "\n";
	return 0;
}
