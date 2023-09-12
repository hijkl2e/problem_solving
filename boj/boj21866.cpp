#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(9);
	for (int i = 0; i < 9; ++i) {
		cin >> A[i];
	}
	string ans = accumulate(A.begin(), A.end(), 0) < 100 ? "none" : "draw";
	for (int i = 0; i < 9; ++i) {
		if (A[i] > (i / 2 + 1) * 100) {
			ans = "hacker";
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
