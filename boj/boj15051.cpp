#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(3);
	for (int i = 0; i < 3; ++i) {
		cin >> A[i];
	}
	int ans = 1e9;
	for (int i = 0; i < 3; ++i) {
		int sum{};
		for (int j = 0; j < 3; ++j) {
			sum += 2 * abs(j - i) * A[j];
		}
		ans = min(ans, sum);
	}
	cout << ans << "\n";
	return 0;
}
