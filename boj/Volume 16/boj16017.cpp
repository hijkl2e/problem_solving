#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(4);
	for (int i = 0; i < 4; ++i) {
		cin >> A[i];
	}
	cout << (A[0] > 7 && A[3] > 7 && A[1] == A[2] ? "ignore" : "answer") << "\n";
	return 0;
}
