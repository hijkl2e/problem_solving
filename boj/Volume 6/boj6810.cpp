#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(3);
	for (int i = 0; i < 3; ++i) {
		cin >> A[i];
	}
	int ans = 3 * A[1] + A[0] + A[2] + 91;
	cout << "The 1-3-sum is " << ans << "\n";
	return 0;
}
