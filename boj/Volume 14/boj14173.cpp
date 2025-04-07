#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(8);
	for (int i = 0; i < 8; ++i) {
		cin >> A[i];
	}
	int x = max(A[2], A[6]) - min(A[0], A[4]);
	int y = max(A[3], A[7]) - min(A[1], A[5]);
	int z = max(x, y);
	int ans = z * z;
	cout << ans << "\n";
	return 0;
}
