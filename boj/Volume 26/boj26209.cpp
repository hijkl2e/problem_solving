#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(8);
	for (int i = 0; i < 8; ++i) {
		cin >> A[i];
	}
	cout << (find(A.begin(), A.end(), 9) == A.end() ? "S" : "F") << "\n";
	return 0;
}
