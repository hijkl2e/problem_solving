#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(5);
	for (int i = 0; i < 5; ++i) {
		cin >> A[i];
	}
	int ans = 1e9;
	for (int i = 0; i < 5; ++i) {
		for (int j = i + 1; j < 5; ++j) {
			for (int k = j + 1; k < 5; ++k) {
				ans = min(ans, lcm(lcm(A[i], A[j]), A[k]));
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
