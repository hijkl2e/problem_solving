#include <bits/stdc++.h>

using namespace std;

int convert(vector<int> A) {
	if (A[0] < A[1]) {
		swap(A[0], A[1]);
	}
	int ret = 10 * A[0] + A[1];
	if (A[0] == 2 && A[1] == 1) {
		ret += 200;
	} else if (A[0] == A[1]) {
		ret += 100;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> S(2);
	vector<int> R(2);
	while (cin >> S[0] >> S[1], S[0]) {
		cin >> R[0] >> R[1];
		int s = convert(S);
		int r = convert(R);
		if (s > r) {
			cout << "Player 1 wins.\n";
		} else if (s < r) {
			cout << "Player 2 wins.\n";
		} else {
			cout << "Tie.\n";
		}
	}
	return 0;
}
