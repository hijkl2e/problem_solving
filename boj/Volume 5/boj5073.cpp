#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(3);
	while (cin >> A[0] >> A[1] >> A[2], A[0]) {
		sort(A.begin(), A.end());
		string ans;
		if (A[0] + A[1] > A[2]) {
			if (A[0] == A[1] && A[1] == A[2]) {
				ans = "Equilateral";
			} else if (A[0] == A[1] || A[1] == A[2]) {
				ans = "Isosceles";
			} else {
				ans = "Scalene";
			}
		} else {
			ans = "Invalid";
		}
		cout << ans << "\n";
	}
	return 0;
}
