#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<int> A(10);
	for (char c : S) {
		++A[c - '0'];
	}
	int ans{};
	if (A[2] + A[0] + A[1] + A[8] == S.size()) {
		if (A[2] && A[0] && A[1] && A[8]) {
			if (A[2] == A[0] && A[0] == A[1] && A[1] == A[8]) {
				ans = 8;
			} else {
				ans = 2;
			}
		} else {
			ans = 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
