#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(4);
	for (int i = 0; i < 4; ++i) {
		cin >> A[i];
	}
	if (A[0] < A[1] && A[1] < A[2] && A[2] < A[3]) {
		cout << "Fish Rising\n";
	} else if (A[0] > A[1] && A[1] > A[2] && A[2] > A[3]) {
		cout << "Fish Diving\n";
	} else if (A[0] == A[1] && A[1] == A[2] && A[2] == A[3]) {
		cout << "Fish At Constant Depth\n";
	} else {
		cout << "No Fish\n";
	}
	return 0;
}
