#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A(8);
	for (int i = 0; i < 8; ++i) {
		getline(cin, A[i]);
	}
	vector<int> R(8);
	vector<int> C(8);
	vector<int> D1(15);
	vector<int> D2(15);
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (A[i][j] == '*') {
				++R[i];
				++C[j];
				++D1[i + j];
				++D2[i - j + 7];
			}
		}
	}
	bool yes = true;
	yes &= count(R.begin(), R.end(), 1) == 8;
	yes &= count(C.begin(), C.end(), 1) == 8;
	yes &= count(D1.begin(), D1.end(), 1) == 8;
	yes &= count(D2.begin(), D2.end(), 1) == 8;
	cout << (yes ? "valid" : "invalid") << "\n";
	return 0;
}
