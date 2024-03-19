#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(3);
	for (int i = 0; i < 3; ++i) {
		cin >> A[i];
	}
	bool flag = true;
	for (int i = 0; i < 3; ++i) {
		if (A[i] % 2) {
			flag = false;
			break;
		}
	}
	int ans = 1;
	for (int i = 0; i < 3; ++i) {
		if (flag || A[i] % 2) {
			ans *= A[i];
		}
	}
	cout << ans << "\n";
	return 0;
}
