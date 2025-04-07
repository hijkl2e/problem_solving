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
	A[2] = min(A[2], A[0] + A[1] - 1);
	int ans = A[0] + A[1] + A[2];
	cout << ans << "\n";
	return 0;
}
