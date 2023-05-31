#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(6);
	for (int i = 0; i < 6; ++i) {
		cin >> A[i];
	}
	int ans = accumulate(A.begin(), A.end(), 0);
	ans -= *min_element(A.begin(), A.begin() + 4) + min(A[4], A[5]);
	cout << ans << "\n";
	return 0;
}
