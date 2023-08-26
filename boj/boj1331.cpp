#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A(36);
	for (int i = 0; i < 36; ++i) {
		cin >> A[i];
	}
	set<string> B(A.begin(), A.end());
	bool yes = B.size() == 36;
	for (int i = 0; i < 36; ++i) {
		int j = (i + 1) % 36;
		int d1 = abs(A[i][0] - A[j][0]);
		int d2 = abs(A[i][1] - A[j][1]);
		yes &= (d1 == 1 && d2 == 2) || (d1 == 2 && d2 == 1);
	}
	cout << (yes ? "Valid" : "Invalid") << "\n";
	return 0;
}
