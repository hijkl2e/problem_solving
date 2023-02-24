#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(5);
	for (int i = 0; i < 5; ++i) {
		cin >> A[i];
	}
	int ans = min({A[0], A[1], A[2]}) + min(A[3], A[4]) - 50;
	cout << ans << "\n";
	return 0;
}
