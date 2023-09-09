#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		vector<int> A(3);
		for (int i = 0; i < 3; ++i) {
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		string ans;
		if (A[0] + A[1] <= A[2]) {
			ans = "invalid!";
		} else if (A[0] == A[1] && A[1] == A[2]) {
			ans = "equilateral";
		} else if (A[0] == A[1] || A[1] == A[2]) {
			ans = "isosceles";
		} else {
			ans = "scalene";
		}
		cout << "Case #" << tc << ": " << ans << "\n";
	}
	return 0;
}
