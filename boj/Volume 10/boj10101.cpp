#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(3);
	for (int i = 0; i < 3; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	string ans;
	if (A[0] + A[1] + A[2] == 180) {
		if (A[0] == 60) {
			ans = "Equilateral";
		} else if (A[0] == A[1] || A[1] == A[2]) {
			ans = "Isosceles";
		} else {
			ans = "Scalene";
		}
	} else {
		ans = "Error";
	}
	cout << ans << "\n";
	return 0;
}
